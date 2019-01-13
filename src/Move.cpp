#include "Move.hpp"
#include <glm/glm.hpp>
/* #include <iostream> */

using namespace glm;

Move::Move(string move) {
  axis = vec3(1, 0, 0);
  axisPosition = 2;
  angle = -90.0;

  if (move[0] == 'b') {
    axis = vec3(0, 0, 1);
    axisPosition = -2;
  }

  if (move[0] == 't') {
    axis = vec3(0, 1, 0);
    axisPosition = 2;
  }

  if (move[0] == 'd') {
    axis = vec3(0, 1, 0);
    axisPosition = 0;
  }

  if (move[0] == 'f') {
    axis = vec3(0, 0, 1);
    axisPosition = 0;
  }

  if (move[0] == 'l') {
    axisPosition = 0;
    angle = 90.0;
  }

  if (move[1] == '\'') {
    angle = -angle;
  }
}
