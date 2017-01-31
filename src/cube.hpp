#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Cube {
 private:
  glm::mat4 model;
  GLuint MatrixID;
  GLuint vertexBuffer;
  GLuint indexBuffer;

 public:
  static const GLfloat vertexList[108];
  Cube(glm::mat4 translation, GLuint matID);
  void draw(glm::mat4 projection, glm::mat4 view);
};
#endif
