#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "OpenGL.hpp"
#include "cube.hpp"
#include "Piece.hpp"

using namespace glm;
using namespace std;

Cube::Cube(vec3 _position, PieceColors _colors) {
  Piece _piece(_position, vec3(3,3,3));
  piece = _piece;
  colors = _colors;
  position = _position;
  newPosition = _position;
  originalPosition = _position;
  vertex_colors = colors.get();

  OpenGL::generateVAO(&VAO);
  OpenGL::bindVAO(VAO);

  OpenGL::bindBufferData(1, vertex_colors);
  OpenGL::bindBufferData(0, CUBE_VERTEX_POSTIIONS);

  OpenGL::bindVAO(0);
}

void Cube::rotate(Move move) {
  piece.rotate(move);
  colors.rotate(move);
  newPosition = vec3(piece.position.x, piece.position.y, piece.position.z);
}

void Cube::draw(mat4 MVP) {
  OpenGL::uniformMatrix(MVP);
  OpenGL::bindVAO(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
  OpenGL::bindVAO(0);
  position = newPosition;
}
