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

Cube::Cube(mat4 translation, PieceColors colors) {
  model = translation;
  glGenBuffers(1, &vertexBuffer);
  glGenBuffers(1, &colorbuffer);
  vertex_colors = colors.get();

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertex_colors.size() * sizeof(vec3), vertex_colors.data(), GL_STATIC_DRAW);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, CUBE_VERTEX_POSTIIONS.size() * sizeof(vec3), CUBE_VERTEX_POSTIIONS.data(),
               GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
  glBindVertexArray(0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

void Cube::draw(glm::mat4 projection, glm::mat4 view) {
  glm::mat4 mvp = projection * view * model;
  OpenGL::uniformMatrix(mvp);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
  glBindVertexArray(0);
}
