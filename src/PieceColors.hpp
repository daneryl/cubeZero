#ifndef PIECE_COLORS_H
#define PIECE_COLORS_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include <map>

#include "CubeVertexInfo.hpp"

using namespace std;
using namespace glm;

class PieceColors {
 private:
 public:
   map<string, vec3> colors = BASE_SIDE_COLORS;

   PieceColors(vec3 position, vec3 maxPosition) {
     if (position.x == maxPosition.x) {
       colors["front"] = SIDE_COLORS["front"];
     }

     if (position.x == maxPosition.x) {
       colors["top"] = SIDE_COLORS["top"];
     }

     if (position.z == maxPosition.z) {
       colors["left"] = SIDE_COLORS["left"];
     }
   }
};
#endif
