#include "src/Scene.hpp"
#include "src/controls.hpp"
#include "src/puzzle.hpp"
#include "src/OpenGL.hpp"

#define GLSL(src) #src

int main(void) {
  OpenGL::init();
  GLFWwindow *window = OpenGL::window;
  GLuint programID = OpenGL::program;

  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

  Puzzle rubik = Puzzle(3, 3, 3);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();

    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(0);

    rubik.draw(Projection, View);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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
