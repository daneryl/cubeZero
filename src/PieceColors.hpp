#ifndef PIECE_COLORS_H
#define PIECE_COLORS_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <map>
#include <vector>

#include "CubeVertexInfo.hpp"
#include "../src/Move.hpp"

using namespace std;
using namespace glm;
using namespace constants;

class PieceColors {
 private:
  void updateColorSideNames() {
    for (auto side : COLOR_ORDER) {
      colorNames[side] = color_names_map[to_string(colors[side])];
    }
  }

 public:
  map<string, vec3> colors = BASE_SIDE_COLORS();
  map<string, string> color_names_map = COLOR_NAMES();
  map<string, vec3> original_colors = BASE_SIDE_COLORS();
  map<string, string> colorNames;

  PieceColors() {}

  PieceColors(vec3 position, vec3 maxPosition) {
    map<string, vec3> side_colors = SIDE_COLORS();

    vec3 max = maxPosition - vec3(1, 1, 1);

    if (position.x == max.x) original_colors["right"] = side_colors["right"];
    if (position.x == 0) original_colors["left"] = side_colors["left"];

    if (position.y == max.y) original_colors["top"] = side_colors["top"];
    if (position.y == 0) original_colors["bottom"] = side_colors["bottom"];

    if (position.z == -max.z) original_colors["back"] = side_colors["back"];
    if (position.z == 0) original_colors["front"] = side_colors["front"];

    colors = original_colors;
    this->updateColorSideNames();
  }

  vector<vec3> get() {
    vector<vec3> vertex_colors;
    for (auto side : COLOR_ORDER) {
      for (int x = 0; x <= 5; ++x) {
        vertex_colors.push_back(original_colors[side]);
      }
    }
    return vertex_colors;
  }

  void rotate(Move move) {
    map<string, vec3> previous_colors = colors;

    if (move.axis == 0) {
      colors["top"] = previous_colors["front"];
      colors["back"] = previous_colors["top"];
      colors["bottom"] = previous_colors["back"];
      colors["front"] = previous_colors["bottom"];

      if (move.angle == 90.0f) {
        colors["front"] = previous_colors["top"];
        colors["bottom"] = previous_colors["front"];
      }
    }

    if (move.axis == 1) {
      colors["front"] = previous_colors["right"];
      colors["left"] = previous_colors["front"];
      colors["back"] = previous_colors["left"];
      colors["right"] = previous_colors["back"];
      if (move.angle == 90.0f) {
        colors["back"] = previous_colors["right"];
        colors["right"] = previous_colors["front"];
      }
    }

    if (move.axis == 2) {
      colors["bottom"] = previous_colors["right"];
      colors["right"] = previous_colors["top"];
      colors["left"] = previous_colors["bottom"];
      colors["top"] = previous_colors["left"];
      if (move.angle == 90.0f) {
        colors["top"] = previous_colors["right"];
        colors["left"] = previous_colors["top"];
      }
    }

    this->updateColorSideNames();
  }
};
#endif
