#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "OpenGL.hpp"
#include "shader.h"

using namespace glm;

GLFWwindow *OpenGL::window;
GLuint OpenGL::program;
GLuint OpenGL::matrixId;
void OpenGL::init() {
  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    // getchar();
  }
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  OpenGL::window = glfwCreateWindow(1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);
  if (OpenGL::window == NULL) {
    fprintf(stderr,
            "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of "
            "the tutorials.\n");
    getchar();
    glfwTerminate();
  }
  glfwMakeContextCurrent(OpenGL::window);
  glfwSetInputMode(OpenGL::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  glewExperimental = true;  // Needed for core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    getchar();
    glfwTerminate();
  }
  glfwSetInputMode(OpenGL::window, GLFW_STICKY_KEYS, GL_TRUE);
  OpenGL::program = LoadShaders("src/vertex.shader", "src/fragment.shader");
  OpenGL::matrixId = glGetUniformLocation(OpenGL::program, "MVP");

  glUseProgram(OpenGL::program);

  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);
  // hide triangles which normal is not towards the camera
  glEnable(GL_CULL_FACE);
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

  // generate THE VAO !
  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);
  //
}

void OpenGL::uniformMatrix(mat4 mvp) {
  glUniformMatrix4fv(OpenGL::matrixId, 1, GL_FALSE, &mvp[0][0]);
}
