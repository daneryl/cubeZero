#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "PieceColors.hpp"

using namespace std;
using namespace glm;
using namespace constants;

class Cube {
 private:
  GLuint VAO;
  glm::mat4 model;
  GLuint MatrixID;
  GLuint vertexBuffer;
  GLuint indexBuffer;
  GLuint colorbuffer;

 public:
  vector<vec3> vertex_colors;
  map<string, vec3> side_colors = BASE_SIDE_COLORS();
  Cube(glm::mat4 translation, PieceColors colors);
  void draw(glm::mat4 projection, glm::mat4 view);
};
#endif
