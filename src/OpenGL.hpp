#ifndef OPENGL_H
#define OPENGL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>
#include <vector>

using namespace glm;
using namespace std;

class OpenGL {
 public:
  static GLFWwindow *window;
  static GLuint program;
  static GLuint matrixId;
  static void init();
  static void uniformMatrix(mat4 mvp);
  static void bindVAO(GLuint VAO);
  static void draw(GLuint VAO, mat4 mvp);
  static void generateVAO(GLuint *VAO, vector<vec3> vertex_positions, vector<vec3> vertex_colors );
  static void bindBufferData(GLuint index, vector<vec3> data);
};
#endif
