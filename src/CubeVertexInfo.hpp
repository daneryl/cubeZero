#ifndef CUBE_VERTEX_H
#define CUBE_VERTEX_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

using namespace glm;
using namespace std;

// clang-format off
const vector<vec3> CUBE_VERTEX_POSTIIONS = {
  //front side
  vec3(1.0f,-1.0f,-1.0f),
  vec3(1.0f, 1.0f, 1.0f),
  vec3(1.0f,-1.0f, 1.0f),
  vec3(1.0f, 1.0f, 1.0f),
  vec3(1.0f,-1.0f,-1.0f),
  vec3(1.0f, 1.0f,-1.0f),
  //right side
  vec3(1.0f, 1.0f,-1.0f),
  vec3(1.0f,-1.0f,-1.0f),
  vec3(-1.0f,-1.0f,-1.0f),
  vec3(1.0f, 1.0f,-1.0f), 
  vec3(-1.0f,-1.0f,-1.0f),
  vec3(-1.0f, 1.0f,-1.0f),
  //back side
  vec3(-1.0f,-1.0f,-1.0f),
  vec3(-1.0f, 1.0f, 1.0f),
  vec3(-1.0f, 1.0f,-1.0f),
  vec3(-1.0f,-1.0f,-1.0f),
  vec3(-1.0f,-1.0f, 1.0f),
  vec3(-1.0f, 1.0f, 1.0f),
  //left side
  vec3(-1.0f, 1.0f, 1.0f),
  vec3(-1.0f,-1.0f, 1.0f),
  vec3(1.0f,-1.0f, 1.0f),
  vec3(1.0f, 1.0f, 1.0f),
  vec3(-1.0f, 1.0f, 1.0f),
  vec3(1.0f,-1.0f, 1.0f),
  //top side
  vec3(1.0f, 1.0f, 1.0f),
  vec3(-1.0f, 1.0f,-1.0f),
  vec3(-1.0f, 1.0f, 1.0f),
  vec3(1.0f, 1.0f, 1.0f),
  vec3(1.0f, 1.0f,-1.0f),
  vec3(-1.0f, 1.0f,-1.0f),
  //bottom side
  vec3(1.0f,-1.0f, 1.0f),
  vec3(-1.0f,-1.0f,-1.0f),
  vec3(1.0f,-1.0f,-1.0f),
  vec3(1.0f,-1.0f, 1.0f),
  vec3(-1.0f,-1.0f, 1.0f),
  vec3(-1.0f,-1.0f,-1.0f),
};
const vector<vec3> SIDE_COLORS = {
  // front side (red)
  vec3(0.0f, 0.0f, 0.0f),
  // right sidef (green)
  vec3(0.0f, 0.0f, 0.0f),
  // back side f(orange)
  vec3(0.0f, 0.0f, 0.0f),
  // left side f(blue)
  vec3(0.0f, 0.0f, 0.0f),
  // top side (yellow)
  vec3(0.0f, 0.0f, 0.0f),
  // bottom sidfe (white)
  vec3(0.0f, 0.0f, 0.0f),
};
// clang-format on
#endif
