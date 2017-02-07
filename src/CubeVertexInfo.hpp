#ifndef CUBE_VERTEX_H
#define CUBE_VERTEX_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <string>
#include <map>

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

map<string, vec3> BASE_SIDE_COLORS = {
  {"front", vec3(0.0f, 0.0f, 0.0f)},
  {"right", vec3(0.0f, 0.0f, 0.0f)},
  {"back", vec3(0.0f, 0.0f, 0.0f)},
  {"left", vec3(0.0f, 0.0f, 0.0f)},
  {"top", vec3(0.0f, 0.0f, 0.0f)},
  {"bottom", vec3(0.0f, 0.0f, 0.0f)}
};
// clang-format on

map<string, vec3> SIDE_COLORS = {
  {"front", vec3(1.0f, 0.0f, 0.0f)},
  {"top", vec3(1.0f, 1.0f, 0.0f)},
  {"back", vec3(1.0f, 0.5f, 0.0f)},
  {"left", vec3(0.0f, 0.0f, 1.0f)},
  {"top", vec3(1.0f, 1.0f, 0.0f)},
  {"bottom", vec3(1.0f, 1.0f, 1.0f)}
};
#endif
