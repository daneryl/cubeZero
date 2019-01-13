#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "OpenGL.hpp"
#include "Piece.hpp"

using namespace glm;
using namespace std;

Piece::Piece(vec3 _position, vec3 _puzzleSize) {
  position = _position;
  puzzleSize = _puzzleSize;
}

void Piece::rotate() {
  float axisTranslation = glm::floor(puzzleSize.x / 2);

  glm::mat4 rotationMat(1); // Creates a identity matrix
  position += vec3(-axisTranslation, -axisTranslation , axisTranslation);
  rotationMat = glm::rotate(rotationMat, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
  position = glm::vec3(rotationMat * glm::vec4(position, 1.0));
  position += glm::round(vec3(axisTranslation, axisTranslation , -axisTranslation));


  position.x = glm::floor(position.x * 5 + 0.5) / 5;
  position.y = glm::floor(position.y * 5 + 0.5) / 5;
  position.z = glm::floor(position.z * 5 + 0.5) / 5;
}
