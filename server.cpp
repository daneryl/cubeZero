#include <zmq.hpp>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/OpenGL.hpp"
#include "src/controls.hpp"
#include "src/puzzle.hpp"

#define GLSL(src) #src


int main(void) {

  zmq::context_t context (1);
  zmq::socket_t socket (context, ZMQ_REP);
  socket.bind ("tcp://*:5555");

  OpenGL::init();
  GLFWwindow *window = OpenGL::window;
  GLuint programID = OpenGL::program;

  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

  Puzzle rubik = Puzzle(3, 3, 3);

  zmq::pollitem_t item = { socket, 0, ZMQ_POLLIN, 0 };
  do {
    zmq::message_t request;
    zmq::poll (&item, 1, 15);

    //
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();

    rubik.draw(Projection, View);

    glfwSwapBuffers(window);
    glfwPollEvents();

    if (item.revents & ZMQ_POLLIN) {
      socket.recv(&request);
      /* std::cout << "Received request: [" << (char*) request.data() << "]" << std::endl; */
      rubik.move((char*) request.data());
      zmq::message_t reply (5);
      memcpy (reply.data (), "World", 5);
      socket.send (reply);
      //  Process task
    }

  }  // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

  glDeleteProgram(programID);

  glfwTerminate();

  return 0;
}
