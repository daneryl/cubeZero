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

  int R_OLD_STATE = GLFW_RELEASE;
  int T_OLD_STATE = GLFW_RELEASE;
  int F_OLD_STATE = GLFW_RELEASE;
  int D_OLD_STATE = GLFW_RELEASE;
  int B_OLD_STATE = GLFW_RELEASE;

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();

    int R_NEW_STATE = glfwGetKey(window, GLFW_KEY_R);
    if (R_NEW_STATE == GLFW_PRESS && R_OLD_STATE == GLFW_RELEASE) {
      rubik.move("r");
    }
    R_OLD_STATE = glfwGetKey(window, GLFW_KEY_R);

    int T_NEW_STATE = glfwGetKey(window, GLFW_KEY_T);
    if (T_NEW_STATE == GLFW_PRESS && T_OLD_STATE == GLFW_RELEASE) {
      rubik.move("t");
    }
    T_OLD_STATE = glfwGetKey(window, GLFW_KEY_T);

    int F_NEW_STATE = glfwGetKey(window, GLFW_KEY_F);
    if (F_NEW_STATE == GLFW_PRESS && F_OLD_STATE == GLFW_RELEASE) {
      rubik.move("f");
    }
    F_OLD_STATE = glfwGetKey(window, GLFW_KEY_F);

    int D_NEW_STATE = glfwGetKey(window, GLFW_KEY_D);
    if (D_NEW_STATE == GLFW_PRESS && D_OLD_STATE == GLFW_RELEASE) {
      rubik.move("d");
    }
    D_OLD_STATE = glfwGetKey(window, GLFW_KEY_D);

    int B_NEW_STATE = glfwGetKey(window, GLFW_KEY_B);
    if (B_NEW_STATE == GLFW_PRESS && B_OLD_STATE == GLFW_RELEASE) {
      rubik.move("b");
    }
    B_OLD_STATE = glfwGetKey(window, GLFW_KEY_B);

    /* if (glfwGetKey(window, GLFW_KEY_F)) { */
    /*   rubik.move(-1); */
    /* } */

    rubik.draw(Projection, View);

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
