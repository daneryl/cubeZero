#ifndef PUZZLE_H
#define PUZZLE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "cube.hpp"

class Puzzle {
 private:
  std::vector<Cube> cubes;

 public:
  Puzzle(int numX, int numY, int numZ, GLuint MatrixID) {
    for (int x = 0; x < numX; ++x) {
      for (int y = 0; y < numY; ++y) {
        for (int z = 0; z < numZ; ++z) {
          float xTranslation = (x * 2.2);
          float yTranslation = (y * 2.2);
          float zTranslation = (z * 2.2);
          cubes.push_back(
              Cube(glm::translate(
                       glm::mat4(1.0f),
                       glm::vec3(xTranslation, yTranslation, zTranslation)),
                   MatrixID));
        }
      }
    }
  }

  void draw(glm::mat4 Projection, glm::mat4 View) {
    std::for_each(cubes.begin(), cubes.end(), [Projection, View](Cube &cube) {
      cube.draw(Projection, View);
    });
  }
};
#endif
