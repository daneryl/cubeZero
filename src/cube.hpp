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
#include "Move.hpp"
#include "Piece.hpp"

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
  float xangle = 0;
  float yangle = 0;
  /* float xrotation = 0.0f; */
  glm::quat orientation = glm::quat();
  glm::quat xrotation = glm::quat();
  glm::quat yrotation = glm::quat();
  glm::quat zrotation = glm::quat();
  Piece piece = Piece(vec3(0, 0, 0), vec3(3,3,3));
  float previousAngle = 0;
  vec3 position;
  vec3 originalPosition;
  vec3 newPosition;
  vector<vec3> vertex_colors;
  map<string, vec3> side_colors = BASE_SIDE_COLORS();
  Cube(vec3 position, PieceColors colors);
  void draw(mat4 MVP);
  void rotate(Move move);
};
#endif
