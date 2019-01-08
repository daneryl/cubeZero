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

  void draw(mat4 Projection, mat4 View) {
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    // cout << deltaTime << "\n";
    for (auto&& cube : cubes) {
      mat4 translation = glm::translate(glm::vec3(cube.position.x * 2.1, cube.position.y * 2.1, cube.position.z * 2.1));
      if (cube.position.x == 2 && direction == 1) {
        //cout << cube.angle << "\n\n";
        if (moving) {
          cube.orientation = glm::normalize(glm::angleAxis(glm::radians(90.0f), vec3(1.0, 0.0, 0.0))) * cube.orientation;
        }
        /* mat4 _rotation = glm::rotate(glm::mat4(1.0f), glm::radians(cube.xangle), vec3(1, 0, 0)); */
        /* mat4 _translation = glm::translate(glm::vec3(0, 1.05 * (y - 1), 1.05 * (z - 1))); */
        /* _translation *= _rotation; */
        /* _translation *= glm::translate(vec3(0, -1.05 * (y - 1), -1.05 * (z - 1))); */
        /* translation *= _rotation; */
      }

      if (cube.position.y == 2 && direction == -1) {
        if (moving) {
          cube.orientation = glm::normalize(glm::angleAxis(glm::radians(90.0f), vec3(0.0, 1.0, 0.0))) * cube.orientation;
        }
        /* mat4 _rotation = glm::rotate(glm::mat4(1.0f), glm::radians(cube.yangle), vec3(0, 1, 0)); */
        /* mat4 _translation = glm::translate(glm::vec3(1.05 * (x - 1), 0, 1.05 * (z - 1))); */
        /* _translation *= _rotation; */
        /* _translation *= glm::translate(vec3(-1.05 * (x - 1), 0, -1.05 * (z - 1))); */
      }

      /* cube.zrotation = glm::angleAxis(glm::radians(0.0f), vec3(0, 0, 1)); */

      /* cube.rotation = cube.rotation * glm::angleAxis(glm::radians(0.0f), vec3(0, 0, 1)); */
      /* glm::vec3 angles(glm::radians(cube.xangle), glm::radians(cube.yangle), 0); */

      /* mat4 xrotation = glm::rotate(glm::mat4(1.0f), glm::radians(cube.xangle), vec3(1, 0, 0)); */
      /* mat4 rotation = glm::rotate(xrotation, glm::radians(cube.yangle), vec3(0, 1, 0)); */
      /* translation *= glm::mat4_cast(glm::quat(glm::radians(0.0f), glm::radians(90.0f), 0, 0)); */
      translation *= glm::mat4_cast(cube.orientation);
      /* translation *= glm::mat4_cast(cube.xrotation) * glm::mat4_cast(cube.yrotation); */
      cube.draw(Projection * View * translation);
    }

    for (auto&& cube : cubes) {
      if (cube.position.x == 2 && direction == 1) {
        if (moving) {
          cube.rotate('x', 2);
        }
      }

      if (cube.position.y == 2 && direction == -1) {
        //cout << cube.angle << "\n\n";
        if (moving) {
          cube.rotate('y', 2);
        }
      }
    }
    moving = false;
    lastTime = currentTime;
  }
};
#endif
