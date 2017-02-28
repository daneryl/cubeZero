#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/OpenGL.hpp"
#include "src/controls.hpp"
#include "src/puzzle.hpp"

#define GLSL(src) #src

//static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  //if (key == GLFW_KEY_R && action == GLFW_PRESS) {
    //cout << "works ?\n";
  //}
//}

int main(void) {
  OpenGL::init();
  GLFWwindow *window = OpenGL::window;
  GLuint programID = OpenGL::program;

  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

  //glfwSetKeyCallback(window, key_callback);
  Puzzle rubik = Puzzle(3, 3, 3);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();

    rubik.draw(Projection * View * glm::translate(vec3(0, 0, 0)));
    if (glfwGetKey(window, GLFW_KEY_R)) {
      rubik.move();
    }
    if (glfwGetKey(window, GLFW_KEY_F)) {
      rubik.move(-1);
    }
    glfwSwapBuffers(window);
    glfwPollEvents();
  }  // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

  // Cleanup VBO
  // glDeleteBuffers(1, &cubeBuffer);
  // glDeleteVertexArrays(1, &VertexArrayID);
  glDeleteProgram(programID);

  // Close OpenGL window and terminate GLFW
  glfwTerminate();

  return 0;
}
