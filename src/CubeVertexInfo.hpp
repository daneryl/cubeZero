#ifndef CUBE_VERTEX_H
#define CUBE_VERTEX_H

#include <glm/glm.hpp>
#include "glm/ext.hpp"
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
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(-1.0f,-1.0f, 1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    //
    //right side
    vec3(1.0f,-1.0f,-1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f,-1.0f,-1.0f),
    vec3(1.0f, 1.0f,-1.0f),
    //
    //back side
    vec3(1.0f, 1.0f,-1.0f),
    vec3(1.0f,-1.0f,-1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(1.0f, 1.0f,-1.0f), 
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    //
    //left side
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f,-1.0f, 1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    //
    //top side
    vec3(1.0f, 1.0f, 1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f,-1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    //
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

  const vec3 yellow = vec3(1.0f, 1.0f, 0.0f);
  const vec3 white = vec3(1.0f, 1.0f, 1.0f);
  const vec3 red = vec3(1.0f, 0.0f, 0.0f);
  const vec3 orange = vec3(1.0f, 0.5f, 0.0f);
  const vec3 green = vec3(0.0f, 1.0f, 0.0f);
  const vec3 blue = vec3(0.0f, 0.0f, 1.0f);

  static map<string, vec3> SIDE_COLORS() {
    map<string, vec3> m;
    m["front"] = red;
    m["right"] = green;
    m["back"] = orange;
    m["left"] = blue;
    m["top"] = yellow;
    m["bottom"] = white;
    return m;
  }

  static map<string, string> COLOR_NAMES() {
    map<string, string> m;
    m[glm::to_string(yellow)] = "yellow";
    m[glm::to_string(white)] = "white";
    m[glm::to_string(red)] = "red";
    m[glm::to_string(orange)] = "orange";
    m[glm::to_string(blue)] = "blue";
    m[glm::to_string(green)] = "green";
    return m;
  }
}
#endif
