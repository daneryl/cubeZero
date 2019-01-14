#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "OpenGL.hpp"
#include "Position.hpp"

using namespace glm;
using namespace std;

Position::Position(vec3 coordinates, vec3 _puzzleSize) {
  x = coordinates.x;
  y = coordinates.y;
  z = coordinates.z;
  puzzleSize = _puzzleSize;
}

void Position::rotate(Move move) {
  float axisTranslation = glm::floor(puzzleSize.x / 2);
  vec3 position = vec3(x, y, z);

  glm::mat4 rotationMat(1); // Creates a identity matrix
  position += vec3(-axisTranslation, -axisTranslation , axisTranslation);
  rotationMat = glm::rotate(rotationMat, glm::radians(move.angle), move.axisVector);
  position = glm::vec3(rotationMat * glm::vec4(position, 1.0));
  position += glm::round(vec3(axisTranslation, axisTranslation , -axisTranslation));


  x = int(position.x);
  y = int(position.y);
  z = int(position.z);
}
