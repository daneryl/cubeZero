#ifndef PIECE_COLORS_H
#define PIECE_COLORS_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <map>
#include <vector>

#include "CubeVertexInfo.hpp"

using namespace std;
using namespace glm;
using namespace constants;

class PieceColors {
 private:
 public:
  map<string, vec3> colors = BASE_SIDE_COLORS();

  PieceColors() {}

  PieceColors(vec3 position, vec3 maxPosition) {
    map<string, vec3> side_colors = SIDE_COLORS();

    if (position.x == maxPosition.x) colors["front"] = side_colors["front"];
    if (position.x == 1) colors["back"] = side_colors["back"];

    if (position.y == maxPosition.y) colors["top"] = side_colors["top"];
    if (position.y == 1) colors["bottom"] = side_colors["bottom"];

    if (position.z == maxPosition.z) colors["left"] = side_colors["left"];
    if (position.z == 1) colors["right"] = side_colors["right"];
  }

  vector<vec3> get() {
    vector<vec3> vertex_colors;
    for (auto side : COLOR_ORDER) {
      for (int x = 0; x <= 5; ++x) {
        vertex_colors.push_back(colors[side]);
      }
    }
    return vertex_colors;
  }
};
#endif
