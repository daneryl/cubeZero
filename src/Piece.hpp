#ifndef PIECE_H
#define PIECE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <map>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "Move.hpp"
#include "Position.hpp"
#include "PieceColors.hpp"

using namespace std;
using namespace glm;
using namespace constants;

class Piece {
 private:
  GLuint VAO;
  glm::quat rotation = glm::quat();
   
 public:
   Piece(vec3 _position, vec3 _puzzleSize);
   PieceColors colors;
   Position position = Position(vec3(0, 0, 0), vec3(0, 0, 0));
   vec3 puzzleSize;
   void rotate(Move move);
   void draw(mat4 MVP);
};
#endif
