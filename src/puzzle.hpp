#ifndef PUZZLE_H
#define PUZZLE_H

#include <GL/glew.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <GLFW/glfw3.h>

#include "PieceColors.hpp"
#include "cube.hpp"

class Puzzle {
 private:
  std::vector<Cube> cubes;

 public:
  float lastTime = 0;
  Puzzle(int numX, int numY, int numZ) {
    for (int x = 0; x < numX; ++x) {
      for (int y = 0; y < numY; ++y) {
        for (int z = 0; z < numZ; ++z) {
          float xTranslation = (x * 2.1);
          float yTranslation = (y * 2.1);
          float zTranslation = (z * 2.1);

          PieceColors piece(vec3(x + 1, y + 1, z + 1), vec3(numX, numY, numZ));
          cubes.push_back(Cube(vec3(x, y, z), piece));
        }
      }
    }
  }

  void draw(glm::mat4 Projection, glm::mat4 View) {
    mat4 MVP = Projection * View;

    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    //cout << deltaTime << "\n";
    for (auto &cube : cubes) {
      mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(cube.angle), vec3(1, 0, 0));
      mat4 translation = glm::translate(glm::vec3(cube.position.x * 2.1, cube.position.y * 2.1, cube.position.z * 2.1));
      if (cube.position.x == 2) {
        if (cube.position.y == 2) {
          translation *= glm::translate(glm::vec3(0, -2.1, 0));
        }
        if (cube.position.y == 0) {
          translation *= glm::translate(glm::vec3(0, 2.1, 0));
        }
        if (cube.position.z == 2) {
          translation *= glm::translate(glm::vec3(0, 0, -2.1));
        }
        if (cube.position.z == 0) {
          translation *= glm::translate(glm::vec3(0, 0, 2.1));
        }

        translation *= rotation;

        if (cube.position.y == 2) {
          translation *= glm::translate(glm::vec3(0, 2.1, 0));
        }
        if (cube.position.y == 0) {
          translation *= glm::translate(glm::vec3(0, -2.1, 0));
        }
        if (cube.position.z == 2) {
          translation *= glm::translate(glm::vec3(0, 0, 2.1));
        }
        if (cube.position.z == 0) {
          translation *= glm::translate(glm::vec3(0, 0, -2.1));
        }
      }
      // if (cube.position.y == 2) {
      // translation *= glm::translate(glm::vec3(0, 0, cube.position.z -1.05));
      //}
      //* glm::translate(glm::vec3(cube.position.x * -2.1, 1, 1))
      //* rotation
      //* glm::translate(glm::vec3(cube.position.x * -2.1, 1, 1))
      //* glm::translate(glm::vec3(cube.position.x * -2.1, cube.position.y * -2.1, cube.position.z * 2.1));
      cube.angle += 100 * deltaTime;
      cube.draw(MVP * translation);
    }
    lastTime = currentTime;
  }
};
#endif
