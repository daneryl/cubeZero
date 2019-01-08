#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "OpenGL.hpp"
#include "cube.hpp"

using namespace glm;
using namespace std;

Cube::Cube(vec3 _position, PieceColors colors) {
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

void Cube::rotate(char axis, int axisPosition) {
  /* if (position[axis] === position) { */
  newPosition = position;
  if (axis == 'x') {
    //corners
    if(position.y == 0 && position.z == 0) {
      newPosition.y = 2;
    }
    if(position.y == 2 && position.z == 0) {
      newPosition.z = 2;
    }
    if(position.y == 2 && position.z == 2) {
      newPosition.y = 0;
    }
    if(position.y == 0 && position.z == 2) {
      newPosition.z = 0;
    }

    //sides
    if(position.y == 0 && position.z == 1) {
      newPosition.z = 0;
      newPosition.y = 1;
    }
    if(position.y == 1 && position.z == 0) {
      newPosition.y = 2;
      newPosition.z = 1;
    }
    if(position.y == 2 && position.z == 1) {
      newPosition.z = 2;
      newPosition.y = 1;
    }
    if(position.y == 1 && position.z == 2) {
      newPosition.z = 1;
      newPosition.y = 0;
    }
  }

  if (axis == 'y') {
    //corners
    if(position.x == 0 && position.z == 0) {
      newPosition.z = 2;
    }
    if(position.x == 2 && position.z == 0) {
      newPosition.x = 0;
    }
    if(position.x == 2 && position.z == 2) {
      newPosition.z = 0;
    }
    if(position.x == 0 && position.z == 2) {
      newPosition.x = 2;
    }
    //sides
    if(position.x == 1 && position.z == 0) {
      newPosition.z = 1;
      newPosition.x = 0;
    }
    if(position.x == 0 && position.z == 1) {
      newPosition.x = 1;
      newPosition.z = 2;
    }
    if(position.x == 1 && position.z == 2) {
      newPosition.z = 1;
      newPosition.x = 2;
    }
    if(position.x == 2 && position.z == 1) {
      newPosition.z = 0;
      newPosition.x = 1;
    }
  }

  if (axis == 'z') {
    if(position.x == 0 && position.y == 0) {
      newPosition.y = 2;
    }
    if(position.x == 0 && position.y == 2) {
      newPosition.x = 2;
    }
    if(position.x == 2 && position.y == 2) {
      newPosition.y = 0;
    }
    if(position.y == 0 && position.x == 2) {
      newPosition.x = 0;
    }
  }
}

void Cube::draw(mat4 MVP) {
  OpenGL::uniformMatrix(MVP);
  OpenGL::bindVAO(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
  OpenGL::bindVAO(0);
  position = newPosition;
}
