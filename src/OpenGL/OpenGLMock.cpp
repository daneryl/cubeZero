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
void OpenGL::bindVAO(GLuint VAO) {}
void OpenGL::generateVAO(GLuint *VAO) {}
void OpenGL::bindBufferData(GLuint index, vector<vec3> data) {}
