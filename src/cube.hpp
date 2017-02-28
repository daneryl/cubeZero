#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "PieceColors.hpp"

using namespace std;
using namespace glm;
using namespace constants;

class Cube {
 private:
  GLuint VAO;
  GLuint MatrixID;
  GLuint vertexBuffer;
  GLuint indexBuffer;
  GLuint colorbuffer;
  float lastTime = 0;

 public:
  float angle = 0;
  float previousAngle = 0;
  vec3 position;
  vector<vec3> vertex_colors;
  map<string, vec3> side_colors = BASE_SIDE_COLORS();
  Cube(vec3 position, PieceColors colors);
  void draw(mat4 MVP);
};
#endif
