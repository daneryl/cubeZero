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
  position = Position(_position, _puzzleSize);
  puzzleSize = _puzzleSize;
}

void Piece::rotate(Move move) {
  position.rotate(move);
}
