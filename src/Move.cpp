#include "Move.hpp"
#include <glm/glm.hpp>
/* #include <iostream> */

using namespace glm;

Move::Move(string move) {
  axisVector = vec3(1, 0, 0);
  axisPosition = 2;
  angle = -90.0;
  axis = 0;

  if (move[0] == 'b') {
    axisVector = vec3(0, 0, 1);
    axisPosition = -2;
    axis = 2;
  }

  if (move[0] == 't') {
    axisVector = vec3(0, 1, 0);
    axisPosition = 2;
    axis = 1;
  }

  if (move[0] == 'd') {
    axisVector = vec3(0, 1, 0);
    axisPosition = 0;
    axis = 1;
  }

  if (move[0] == 'f') {
    axisVector = vec3(0, 0, 1);
    axisPosition = 0;
    axis = 2;
  }

  if (move[0] == 'l') {
    axisPosition = 0;
    angle = 90.0;
  }

  if (move[1] == '\'') {
    angle = -angle;
  }
}
