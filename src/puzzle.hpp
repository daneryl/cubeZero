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
#include <vector>

#include "PieceColors.hpp"
#include "cube.hpp"

class Puzzle {
 private:
  std::vector<Cube> cubes;
  bool moving = false;
  int moveDegrees = 90;
  int direction = 1;
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

  void move(int dir = 1) {
    if (!moving) {
      direction = dir;
      moving = true;
    }
  }

  void draw(mat4 MVP) {
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    // cout << deltaTime << "\n";
    for (auto&& cube : cubes) {
      mat4 translation = glm::translate(glm::vec3(cube.position.x * 2.1, cube.position.y * 2.1, cube.position.z * 2.1));
      mat4 _rotation = glm::rotate(glm::mat4(1.0f), glm::radians(cube.angle), vec3(1, 0, 0));
      if (cube.position.x == 2) {
        //cout << cube.angle << "\n\n";
        mat4 _translation = glm::translate(glm::vec3(0, 1.05 * (y - 1), 1.05 * (z - 1)));
        _translation *= _rotation;
        _translation *= glm::translate(vec3(0, -1.05 * (y - 1), -1.05 * (z - 1)));
        translation = _translation * translation;
      }

      bool needToStop = true;
      for (auto&& cube : cubes) {
        if (cube.position.x == 2) {
          if (direction == 1) {
            needToStop = needToStop && cube.angle == cube.previousAngle + moveDegrees;
            if (cube.angle >= cube.previousAngle + moveDegrees) {
              cube.angle = cube.previousAngle + moveDegrees;
            }
          }
          if (direction == -1) {
            needToStop = needToStop && cube.angle == cube.previousAngle - moveDegrees;
            if (cube.angle <= cube.previousAngle - moveDegrees) {
              cube.angle = cube.previousAngle - moveDegrees;
            }
          }
        }
      }

      if (cube.position.x == 2 && needToStop) {
        for (auto&& cube : cubes) {
          cube.previousAngle = cube.angle;
        }
        moving = false;
      }
      // not working properly, moving = false needs to happen when all cubes are at 90º
      if (moving && cube.position.x == 2) {
        if (direction == 1) {
          cube.angle += (30 * deltaTime) * 15;
        }
        if (direction == -1) {
          cube.angle -= (30 * deltaTime) * 15;
        }
      }

      // cout << cube.angle << "\n";

      // store angles y and x instead of only one angle
      // if (glm::degrees(glm::radians(cube.angle)) == 90) {
      // mat4 _rotation = glm::rotate(glm::mat4(1.0f), glm::radians(cube.angle), vec3(0, y, 0));
      // if (cube.position.y == 7) {
      // mat4 _translation = glm::translate(glm::vec3(0, 1.05 * (y - 1), 1.05 * (z - 1)));
      //_translation *= _rotation;
      //_translation *= glm::translate(vec3(0, -1.05 * (y - 1), -1.05 * (z - 1)));
      // translation = _translation * translation;
      //}
      // if (glm::degrees(glm::radians(cube.angle)) < 90) {
      // cube.angle += 30 * deltaTime;
      //}
      //}

      cube.draw(MVP * translation);
    }
    lastTime = currentTime;
  }
};
#endif
