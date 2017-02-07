#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"

using namespace std;
using namespace glm;

class Cube {
 private:
  glm::mat4 model;
  GLuint MatrixID;
  GLuint vertexBuffer;
  GLuint indexBuffer;
  GLuint colorbuffer;

 public:
  vector<vec3> vertex_colors;
  map<string, vec3> side_colors = BASE_SIDE_COLORS;
  Cube(glm::mat4 translation);
  void draw(glm::mat4 projection, glm::mat4 view);
  void bottom() {
    //side_colors[5] = vec3(1.0f, 1.0f, 1.0f);
  }
  void top() {
    //side_colors[4] = vec3(1.0f, 1.0f, 0.0f);
  }
  void left() {
    //side_colors[3] = vec3(0.0f, 0.0f, 1.0f);
  }
  void right() {
    //side_colors[1] = vec3(0.0f, 1.0f, 0.0f);
  }
  void front() {
    //side_colors[0] = vec3(1.0f, 0.0f, 0.0f);
  }
  void back() {
    //side_colors[2] = vec3(1.0f, 0.5f, 0.0f);
  }
};
#endif
