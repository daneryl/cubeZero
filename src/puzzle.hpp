#ifndef PUZZLE_H
#define PUZZLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/common.hpp>
#include <vector>

#include "PieceColors.hpp"
#include "cube.hpp"

class Puzzle {
 private:
  std::vector<Cube> pieces;
  int x;
  int y;
  int z;

 public:
  float lastTime = 0;
  Puzzle(int numX, int numY, int numZ) {
    x = numX;
    y = numY;
    z = numZ;
    for (int x = 0; x < numX; ++x) {
      for (int y = 0; y < numY; ++y) {
        for (int z = 0; z > -numZ; --z) {
          PieceColors piece(vec3(x, y, z), vec3(numX, numY, numZ));
          pieces.push_back(Cube(vec3(x, y, z), piece));
        }
      }
    }
  }

  void move(string movement) {
    Move move(movement);
    for (auto&& cube : pieces) {
      if (cube.position[move.axis] == move.axisPosition) {
        cube.orientation = glm::normalize(glm::angleAxis(glm::radians(move.angle), move.axisVector) * cube.orientation);
        cube.rotate(move);
      }
    }
  }

  void draw(mat4 Projection, mat4 View) {
    for (auto&& cube : pieces) {
      mat4 translation = glm::translate(glm::vec3(cube.position.x * 2.1, cube.position.y * 2.1, cube.position.z * 2.1));
      cube.draw(Projection * View * translation * glm::mat4_cast(cube.orientation));
    }
  }

  map<string, vector<vector<string>>> state() {
    map<string, vector<vector<string>>> state;

    state["front"] = vector<vector<string>>();
    state["front"].push_back({ "string", "string", "string" });
    state["front"].push_back({ "string", "string", "string" });
    state["front"].push_back({ "string", "string", "string" });

    state["back"] = vector<vector<string>>();
    state["back"].push_back({ "string", "string", "string" });
    state["back"].push_back({ "string", "string", "string" });
    state["back"].push_back({ "string", "string", "string" });

    state["top"] = vector<vector<string>>();
    state["top"].push_back({ "string", "string", "string" });
    state["top"].push_back({ "string", "string", "string" });
    state["top"].push_back({ "string", "string", "string" });

    state["bottom"] = vector<vector<string>>();
    state["bottom"].push_back({ "string", "string", "string" });
    state["bottom"].push_back({ "string", "string", "string" });
    state["bottom"].push_back({ "string", "string", "string" });

    state["left"] = vector<vector<string>>();
    state["left"].push_back({ "string", "string", "string" });
    state["left"].push_back({ "string", "string", "string" });
    state["left"].push_back({ "string", "string", "string" });

    state["right"] = vector<vector<string>>();
    state["right"].push_back({ "string", "string", "string" });
    state["right"].push_back({ "string", "string", "string" });
    state["right"].push_back({ "string", "string", "string" });

    for (auto&& piece : pieces) {
      if (piece.position.z == 0) {
        if (piece.position.y == 2) {
          state["front"][0][piece.position.x] = piece.colors.colorNames["front"];
        }
        if (piece.position.y == 1) {
          state["front"][1][piece.position.x] = piece.colors.colorNames["front"];
        }
        if (piece.position.y == 0) {
          state["front"][2][piece.position.x] = piece.colors.colorNames["front"];
        }
      }
      if (piece.position.z == -2) {
        if (piece.position.y == 2) {
          state["back"][0][-piece.position.x + 2] = piece.colors.colorNames["back"];
        }
        if (piece.position.y == 1) {
          state["back"][1][-piece.position.x + 2] = piece.colors.colorNames["back"];
        }
        if (piece.position.y == 0) {
          state["back"][2][-piece.position.x + 2] = piece.colors.colorNames["back"];
        }
      }

      if (piece.position.y == 2) {
        if (piece.position.z == -2) {
          state["top"][0][piece.position.x] = piece.colors.colorNames["top"];
        }
        if (piece.position.z == -1) {
          state["top"][1][piece.position.x] = piece.colors.colorNames["top"];
        }
        if (piece.position.z == 0) {
          state["top"][2][piece.position.x] = piece.colors.colorNames["top"];
        }
      }

      if (piece.position.y == 0) {
        if (piece.position.z == -2) {
          state["bottom"][2][piece.position.x] = piece.colors.colorNames["bottom"];
        }
        if (piece.position.z == -1) {
          state["bottom"][1][piece.position.x] = piece.colors.colorNames["bottom"];
        }
        if (piece.position.z == 0) {
          state["bottom"][0][piece.position.x] = piece.colors.colorNames["bottom"];
        }
      }

      if (piece.position.x == 0) {
        if (piece.position.y == 2) {
          state["left"][0][piece.position.z + 2] = piece.colors.colorNames["left"];
        }
        if (piece.position.y == 1) {
          state["left"][1][piece.position.z + 2] = piece.colors.colorNames["left"];
        }
        if (piece.position.y == 0) {
          state["left"][2][piece.position.z + 2] = piece.colors.colorNames["left"];
        }
      }
      if (piece.position.x == 2) {
        if (piece.position.y == 2) {
          state["right"][0][-piece.position.z] = piece.colors.colorNames["right"];
        }
        if (piece.position.y == 1) {
          state["right"][1][-piece.position.z] = piece.colors.colorNames["right"];
        }
        if (piece.position.y == 0) {
          state["right"][2][-piece.position.z] = piece.colors.colorNames["right"];
        }
      }
    }

    return state;
  }
};
#endif
