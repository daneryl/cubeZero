#ifndef POSITION_H
#define POSITION_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <map>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "Move.hpp"

using namespace std;
using namespace glm;
using namespace constants;

class Position {
 private:
   
 public:
   Position(vec3 _position, vec3 _puzzleSize);
   int x;
   int y;
   int z;
   vec3 puzzleSize;
   void rotate(Move move);
};
#endif
