#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Move
{
  private:


  public:
    Move(string move);
    int axis;
    vec3 axisVector;
    int axisPosition;
    float angle;
};

#endif /* MOVE_H */
