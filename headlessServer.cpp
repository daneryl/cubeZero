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
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#define GLSL(src) #src


int main(void) {

  zmq::context_t context (1);
  zmq::socket_t socket (context, ZMQ_REP);
  socket.bind ("tcp://*:5556");

  OpenGL::init();
  GLFWwindow *window = OpenGL::window;
  GLuint programID = OpenGL::program;

  /* printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION)); */

  Puzzle rubik = Puzzle(3, 3, 3);

  zmq::pollitem_t item = { socket, 0, ZMQ_POLLIN, 0 };
  do {
    zmq::message_t request;
    zmq::poll (&item, 1, 15);

    //
    OpenGL::clear();
    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();

    rubik.draw(Projection, View);

    OpenGL::swapBuffers();
    glfwPollEvents();

    if (item.revents & ZMQ_POLLIN) {
      socket.recv(&request);
      std::cout << "Received request: [" << std::string(static_cast<char*>(request.data()), request.size()) << "]" << std::endl;
      rubik.move(std::string(static_cast<char*>(request.data()), request.size()));
      map<string, vector<vector<string>>> state = rubik.state();

      json j_map(state);
      string jsonState = j_map.dump();
      /* cout << jsonState << "\n\n"; */
      zmq::message_t reply (jsonState.size());
      memcpy (reply.data (), jsonState.c_str(), jsonState.size());
      socket.send (reply);
      //  Process task
    }

  }  // Check if the ESC key was pressed or the window was closed
  while (1);

  /* glDeleteProgram(programID); */

  glfwTerminate();

  return 0;
}
