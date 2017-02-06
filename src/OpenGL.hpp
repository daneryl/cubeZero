#ifndef OPENGL_H
#define OPENGL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class OpenGL {
 public:
  static GLFWwindow *window;
  static GLuint program;
  static GLuint matrixId;
  static void init();
  static void uniformMatrix(mat4 mvp);
};
#endif
