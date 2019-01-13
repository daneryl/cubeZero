#include "../src/PieceColors.hpp"
#include "../src/CubeVertexInfo.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"

using namespace constants;

SCENARIO("PieceColors", "[PieceColors]") {
  map<string, vec3> side_colors = SIDE_COLORS();
  map<string, vec3> base_side_colors = BASE_SIDE_COLORS();
  GIVEN("Given PiecePosition and maxPieces") {

    WHEN("piece its in the front") {
      PieceColors piece(vec3(0, 0, 0), vec3(3, 3, 3));
      THEN("front colors should be set and all other colors should be black") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.colors["bottom"]) == to_string(side_colors["bottom"]));
        REQUIRE(to_string(piece.colors["top"]) == to_string(base_side_colors["top"]));
        REQUIRE(to_string(piece.colors["left"]) == to_string(side_colors["left"]));
        REQUIRE(to_string(piece.colors["right"]) == to_string(base_side_colors["right"]));
        REQUIRE(to_string(piece.colors["back"]) == to_string(base_side_colors["back"]));
      }
    }

    WHEN("piece its a back-top edge") {
      PieceColors piece(vec3(0, 2, -2), vec3(3, 3, 3));
      THEN("front and top colors should be set") {
        REQUIRE(to_string(piece.colors["back"]) == to_string(side_colors["back"]));
        REQUIRE(to_string(piece.colors["left"]) == to_string(side_colors["left"]));
        REQUIRE(to_string(piece.colors["top"]) == to_string(side_colors["top"]));
      }
    }

    WHEN("piece its a front-top edge") {
      PieceColors piece(vec3(0, 2, 0), vec3(3, 3, 3));
      THEN("front and top colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.colors["top"]) == to_string(side_colors["top"]));
      }
    }

    WHEN("piece its a front-bottom edge") {
      PieceColors piece(vec3(0, 0, 0), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.colors["bottom"]) == to_string(side_colors["bottom"]));
      }
    }

    WHEN("piece its a front-left edge") {
      PieceColors piece(vec3(0, 1, 0), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.colors["left"]) == to_string(side_colors["left"]));
      }
    }

    WHEN("piece its a back-right-bottom corner") {
      PieceColors piece(vec3(2, 0, -2), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.colors["back"]) == to_string(side_colors["back"]));
        REQUIRE(to_string(piece.colors["right"]) == to_string(side_colors["right"]));
        REQUIRE(to_string(piece.colors["bottom"]) == to_string(side_colors["bottom"]));
      }
    }
  }

  GIVEN("A Piece Color object") {
    WHEN("calling data()") {
      PieceColors piece(vec3(0, 2, 0), vec3(3, 3, 3));
      THEN("should expand colors to fit cube sides vertex") {
        vector<vec3> expanded = piece.get();
        REQUIRE(to_string(expanded[0]) == to_string(vec3(1.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[1]) == to_string(vec3(1.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[2]) == to_string(vec3(1.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[3]) == to_string(vec3(1.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[4]) == to_string(vec3(1.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[5]) == to_string(vec3(1.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[6]) == to_string(vec3(0.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[33]) == to_string(vec3(0.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[34]) == to_string(vec3(0.0f, 0.0f, 0.0f)));
        REQUIRE(to_string(expanded[35]) == to_string(vec3(0.0f, 0.0f, 0.0f)));
      }
    }
  }
}
