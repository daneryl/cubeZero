#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <vector>

#include <GLFW/glfw3.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

#include "src/Scene.hpp"
#include "src/controls.hpp"
#include "src/cube.hpp"
#include "src/puzzle.hpp"
#include "src/shader.h"

#define GLSL(src) #src

int main(void) {
  Scene scene;
  GLFWwindow *window = scene.window;
  GLuint programID = scene.program;
  GLuint MatrixID = scene.matrixId;

  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // clang-format off
  static vec3 g_color_buffer_data[] = {
    // front side (red)
    vec3(1.0f, 0.0f, 0.0f),
    vec3(1.0f, 0.0f, 0.0f),
    vec3(1.0f, 0.0f, 0.0f),
    vec3(1.0f, 0.0f, 0.0f),
    vec3(1.0f, 0.0f, 0.0f),
    vec3(1.0f, 0.0f, 0.0f),
    // right sidef (green)
    vec3(0.0f, 1.0f, 0.0f),
    vec3(0.0f, 1.0f, 0.0f),
    vec3(0.0f, 1.0f, 0.0f),
    vec3(0.0f, 1.0f, 0.0f),
    vec3(0.0f, 1.0f, 0.0f),
    vec3(0.0f, 1.0f, 0.0f),
    // back side f(orange)
    vec3(1.0f, 0.5f, 0.0f),
    vec3(1.0f, 0.5f, 0.0f),
    vec3(1.0f, 0.5f, 0.0f),
    vec3(1.0f, 0.5f, 0.0f),
    vec3(1.0f, 0.5f, 0.0f),
    vec3(1.0f, 0.5f, 0.0f),
    // left side f(blue)
    vec3(0.0f, 0.0f, 1.0f),
    vec3(0.0f, 0.0f, 1.0f),
    vec3(0.0f, 0.0f, 1.0f),
    vec3(0.0f, 0.0f, 1.0f),
    vec3(0.0f, 0.0f, 1.0f),
    vec3(0.0f, 0.0f, 1.0f),
    // top side (fyellofw)
    vec3(1.0f, 1.0f, 0.0f),
    vec3(1.0f, 1.0f, 0.0f),
    vec3(1.0f, 1.0f, 0.0f),
    vec3(1.0f, 1.0f, 0.0f),
    vec3(1.0f, 1.0f, 0.0f),
    vec3(1.0f, 1.0f, 0.0f),
    // bottom sidfe (white)
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f)
  };
  // clang format on

  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

  GLuint colorbuffer;
  glGenBuffers(1, &colorbuffer);

  Puzzle rubik = Puzzle(3, 3, 3, MatrixID);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    computeMatricesFromInputs(window);
    glm::mat4 Projection = getProjectionMatrix();
    glm::mat4 View = getViewMatrix();
    // Use our shader

    // srand (static_cast <unsigned> (time(0)));

    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(1,         // attribute. No particular reason for 1, but must
                                     // match the layout in the shader.
                          3,         // size
                          GL_FLOAT,  // type
                          GL_FALSE,  // normalized?
                          0,         // stride
                          (void *)0  // array buffer offset
                          );

    glEnableVertexAttribArray(0);

    rubik.draw(Projection, View);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    // Swap buffers
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
