#include <GL/glew.h>
#include <stdio.h>

#include "../OpenGL.hpp"
#include "../shader.h"

using namespace std;
using namespace glm;

GLFWwindow *OpenGL::window;
GLuint OpenGL::program;
GLuint OpenGL::matrixId;

void OpenGL::init() {}
void OpenGL::uniformMatrix(mat4 mvp) {}
void OpenGL::bindVAO(GLuint VAO) {};
void OpenGL::draw(GLuint VAO, mat4 mvp) {}
void OpenGL::generateVAO(GLuint *VAO, vector<vec3> vertex_positions, vector<vec3> vertex_colors ) {}
void OpenGL::bindBufferData(GLuint index, vector<vec3> data) {}
void OpenGL::clear() {}
void OpenGL::swapBuffers() {}
void OpenGL::getCursorPosition(double *x, double *y) {}
