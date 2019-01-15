#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../OpenGL.hpp"
#include "../shader.h"

#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/ 
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
 
using namespace std;

std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}

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

  string fullPath = __FILE__;
  string dirname = fullPath.substr(0, fullPath.find_last_of("\\/"));

  string vertex = dirname + "/../vertex.shader";
  string fragment = dirname + "/../fragment.shader";
  OpenGL::program = LoadShaders(vertex, fragment);
  OpenGL::matrixId = glGetUniformLocation(OpenGL::program, "MVP");

  glUseProgram(OpenGL::program);

  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);
  // hide triangles which normal is not towards the camera
  glEnable(GL_CULL_FACE);
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

void OpenGL::uniformMatrix(mat4 mvp) {
  glUniformMatrix4fv(OpenGL::matrixId, 1, GL_FALSE, &mvp[0][0]);
}

void OpenGL::bindVAO(GLuint VAO) {
  glBindVertexArray(VAO);
}

void OpenGL::generateVAO(GLuint *VAO) {
  glGenVertexArrays(1, VAO);
}

void OpenGL::bindBufferData(GLuint index, vector<vec3> data) {
  GLuint bufferId;
  glGenBuffers(1, &bufferId);
  glBindBuffer(GL_ARRAY_BUFFER, bufferId);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(vec3), data.data(), GL_STATIC_DRAW);
  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
}
