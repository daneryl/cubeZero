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

using namespace std;
using namespace glm;
using namespace constants;

class Piece {
 private:
   
 public:
   Piece(vec3 _position, vec3 _puzzleSize);
   Position position = Position(vec3(0, 0, 0), vec3(0, 0, 0));
   vec3 puzzleSize;
   void rotate(Move move);
};
#endif
