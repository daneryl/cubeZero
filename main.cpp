#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "src/controls.hpp"
#include "src/puzzle.hpp"
#include "src/OpenGL.hpp"

#define GLSL(src) #src

int main(void) {
  OpenGL::init();
  GLFWwindow *window = OpenGL::window;
  GLuint programID = OpenGL::program;

  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

  Puzzle rubik = Puzzle(8, 8, 8);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();

    rubik.draw(Projection * View * glm::translate(vec3(0, 0, 0)));

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
