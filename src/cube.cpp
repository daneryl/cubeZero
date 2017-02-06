#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "cube.hpp"
#include "CubeVertexInfo.hpp"
#include "OpenGL.hpp"

using namespace glm;
using namespace std;

Cube::Cube(mat4 translation) {
  model = translation;
  glGenBuffers(1, &vertexBuffer);
  glGenBuffers(1, &colorbuffer);
}

void Cube::draw(glm::mat4 projection, glm::mat4 view) {
  vector<vec3> vertex_colors;
  for (int side = 0; side < side_colors.size(); ++side) {
    for (int x = 0; x <= 5; ++x) {
      vertex_colors.push_back(side_colors.at(side));
    }
  }

  glm::mat4 mvp = projection * view * model;
  OpenGL::uniformMatrix(mvp);

  glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertex_colors.size() * sizeof(vec3), vertex_colors.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, CUBE_VERTEX_POSTIIONS.size() * sizeof(vec3), CUBE_VERTEX_POSTIIONS.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

  glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
}
