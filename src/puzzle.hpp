#ifndef PUZZLE_H
#define PUZZLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/common.hpp>
#include <vector>

#include "PieceColors.hpp"
#include "cube.hpp"

class Puzzle {
 private:
  std::vector<Cube> cubes;
  bool moving = false;
  int moveDegrees = 90;
  string movement;
  int x;
  int y;
  int z;

 public:
  float lastTime = 0;
  Puzzle(int numX, int numY, int numZ) {
    x = numX;
    y = numY;
    z = numZ;
    for (int x = 0; x < numX; ++x) {
      for (int y = 0; y < numY; ++y) {
        for (int z = 0; z > -numZ; --z) {
          PieceColors piece(vec3(x, y, z), vec3(numX, numY, numZ));
          cubes.push_back(Cube(vec3(x, y, z), piece));
        }
      }
    }
  }

  void move(string _move) {
    if (!moving) {
      movement = _move;
      moving = true;
    }
  }

  void draw(mat4 Projection, mat4 View) {
    Move move(movement);
    for (auto&& cube : cubes) {
      mat4 translation = glm::translate(glm::vec3(cube.position.x * 2.1, cube.position.y * 2.1, cube.position.z * 2.1));

      if (cube.position[move.axis] == move.axisPosition) {
        if (moving) {
          cube.orientation = glm::normalize(glm::angleAxis(glm::radians(move.angle), move.axisVector) * cube.orientation);
          cube.rotate(move);
        }
      }

      cube.draw(Projection * View * translation * glm::mat4_cast(cube.orientation));
    }

    moving = false;
  }
};
#endif
