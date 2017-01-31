#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "cube.hpp"
#include "shader.h"

class Scene {
 public:
  GLFWwindow *window;
  GLuint program;
  GLuint matrixId;

  Scene() {
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
    window = glfwCreateWindow(1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);
    if (window == NULL) {
      fprintf(stderr,
              "Failed to open GLFW window. If you have an Intel GPU, they "
              "are not 3.3 compatible. Try the 2.1 version of the "
              "tutorials.\n");
      getchar();
      glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = true;  // Needed for core profile
    if (glewInit() != GLEW_OK) {
      fprintf(stderr, "Failed to initialize GLEW\n");
      getchar();
      glfwTerminate();
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    program = LoadShaders("src/vertex.shader", "src/fragment.shader");
    matrixId = glGetUniformLocation(program, "MVP");
    glUseProgram(program);

    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
    // hide triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
  }
};
#endif
