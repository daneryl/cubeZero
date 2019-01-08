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
  char direction;
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
        for (int z = 0; z < numZ; ++z) {
          PieceColors piece(vec3(x + 1, y + 1, z + 1), vec3(numX, numY, numZ));
          cubes.push_back(Cube(vec3(x, y, z), piece));
        }
      }
    }
  }

  void move(int dir) {
    if (!moving) {
      direction = dir;
      moving = true;
    }
  }

  void draw(mat4 Projection, mat4 View) {
    for (auto&& cube : cubes) {
      mat4 translation = glm::translate(glm::vec3(cube.position.x * 2.1, cube.position.y * 2.1, cube.position.z * 2.1));
      if (cube.position.x == 2 && direction == 'x') {
        if (moving) {
          cube.orientation = glm::normalize(glm::angleAxis(glm::radians(90.0f), vec3(1.0, 0.0, 0.0))) * cube.orientation;
          cube.rotate('x', 2);
        }
      }

      if (cube.position.y == 2 && direction == 'y') {
        if (moving) {
          cube.orientation = glm::normalize(glm::angleAxis(glm::radians(90.0f), vec3(0.0, 1.0, 0.0))) * cube.orientation;
          cube.rotate('y', 2);
        }
      }

      if (cube.position.z == 2 && direction == 'z') {
        if (moving) {
          cube.orientation = glm::normalize(glm::angleAxis(glm::radians(-90.0f), vec3(0.0, 0.0, 1.0))) * cube.orientation;
          cube.rotate('z', 2);
        }
      }

      translation *= glm::mat4_cast(cube.orientation);
      cube.draw(Projection * View * translation);
    }

    moving = false;
  }
};
#endif
