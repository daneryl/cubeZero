#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "OpenGL.hpp"
#include "Piece.hpp"
#include "PieceColors.hpp"

using namespace glm;
using namespace std;

Piece::Piece(vec3 _position, vec3 _puzzleSize) {
  puzzleSize = _puzzleSize;
  colors = PieceColors(_position, _puzzleSize);
  position = Position(_position, _puzzleSize);
  vector<vec3> vertex_colors = colors.get();
  OpenGL::generateVAO(&VAO, CUBE_VERTEX_POSTIIONS, vertex_colors);
}

void Piece::rotate(Move move) {
  if (position.get(move.axis) == move.axisPosition) {
    position.rotate(move);
    rotation = glm::normalize(glm::angleAxis(glm::radians(move.angle), move.axisVector) * rotation);
    colors.rotate(move);
  }
}

void Piece::draw(mat4 MVP) {
  mat4 translation = glm::translate(glm::vec3(position.x * 2.1, position.y * 2.1, position.z * 2.1));
  OpenGL::draw(VAO, MVP * translation * glm::mat4_cast(rotation));
}
