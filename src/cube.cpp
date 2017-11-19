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
  vertex_colors = colors.get();

  OpenGL::generateVAO(&VAO);
  OpenGL::bindVAO(VAO);

  OpenGL::bindBufferData(1, vertex_colors);
  OpenGL::bindBufferData(0, CUBE_VERTEX_POSTIIONS);

  OpenGL::bindVAO(0);
}

void Cube::draw(mat4 MVP) {
  double currentTime = glfwGetTime();
  float deltaTime = float(currentTime - lastTime);

  OpenGL::uniformMatrix(MVP);
  OpenGL::bindVAO(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
  OpenGL::bindVAO(0);

  lastTime = currentTime;
}
