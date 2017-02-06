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

#include "cube.hpp"

class Puzzle {
 private:
  std::vector<Cube> cubes;

 public:
  Puzzle(int numX, int numY, int numZ) {
    for (int x = 0; x < numX; ++x) {
      for (int y = 0; y < numY; ++y) {
        for (int z = 0; z < numZ; ++z) {
          float xTranslation = (x * 2.1);
          float yTranslation = (y * 2.1);
          float zTranslation = (z * 2.1);

          Cube cube = Cube(glm::translate(glm::mat4(1.0f), glm::vec3(xTranslation, yTranslation, zTranslation)));
          //printf("x = %f, y = %f, z = %f\n", xTranslation, yTranslation, zTranslation);
          if (x == 0) {
            cube.back();
          }
          if (x == numX-1) {
            cube.front();
          }
          if (y == 0) {
            cube.bottom();
          }
          if (y == numY-1) {
            cube.top();
          }
          if (z == 0) {
            cube.right();
          }
          if (z == numZ-1) {
            cube.left();
          }
          printf("\n");

          cubes.push_back(cube);
        }
      }
    }
  }

  void draw(glm::mat4 Projection, glm::mat4 View) {
    std::for_each(cubes.begin(), cubes.end(), [Projection, View](Cube &cube) { cube.draw(Projection, View); });
  }
};
#endif
