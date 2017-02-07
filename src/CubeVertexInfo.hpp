#ifndef CUBE_VERTEX_H
#define CUBE_VERTEX_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <map>
#include <string>
#include <vector>

using namespace glm;
using namespace std;

namespace constants {
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

  const vector<string> COLOR_ORDER = {
    "front", "right", "back", "left", "top", "bottom"
  };

  static map<string, vec3> BASE_SIDE_COLORS() {
    map<string, vec3> m;
    m["front"] = vec3(0.0f, 0.0f, 0.0f);
    m["right"] = vec3(0.0f, 0.0f, 0.0f);
    m["back"] = vec3(0.0f, 0.0f, 0.0f);
    m["left"] = vec3(0.0f, 0.0f, 0.0f),
    m["top"] = vec3(0.0f, 0.0f, 0.0f);
    m["bottom"] = vec3(0.0f, 0.0f, 0.0f);
    return m;
  }

  static map<string, vec3> SIDE_COLORS() {
    map<string, vec3> m;
    m["front"] = vec3(1.0f, 0.0f, 0.0f);
    m["right"] = vec3(0.0f, 1.0f, 0.0f);
    m["back"] = vec3(1.0f, 0.5f, 0.0f);
    m["left"] = vec3(0.0f, 0.0f, 1.0f),
    m["top"] = vec3(1.0f, 1.0f, 0.0f);
    m["bottom"] = vec3(1.0f, 1.0f, 1.0f);
    return m;
  }
}
#endif
