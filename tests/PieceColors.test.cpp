#include "../src/PieceColors.hpp"
#include "../src/CubeVertexInfo.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"
#include "../src/Move.hpp"

using namespace constants;

SCENARIO("PieceColors", "[PieceColors]") {
  map<string, vec3> side_colors = SIDE_COLORS();
  map<string, vec3> base_side_colors = BASE_SIDE_COLORS();
  GIVEN("Given PiecePosition and maxPieces") {

    WHEN("piece its in the front") {
      PieceColors piece(vec3(0, 0, 0), vec3(3, 3, 3));
      THEN("front colors should be set and all other colors should be black") {
        REQUIRE(to_string(piece.original_colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.original_colors["bottom"]) == to_string(side_colors["bottom"]));
        REQUIRE(to_string(piece.original_colors["top"]) == to_string(base_side_colors["top"]));
        REQUIRE(to_string(piece.original_colors["left"]) == to_string(side_colors["left"]));
        REQUIRE(to_string(piece.original_colors["right"]) == to_string(base_side_colors["right"]));
        REQUIRE(to_string(piece.original_colors["back"]) == to_string(base_side_colors["back"]));
      }
    }

    WHEN("piece its a back-top edge") {
      PieceColors piece(vec3(0, 2, -2), vec3(3, 3, 3));
      THEN("front and top colors should be set") {
        REQUIRE(to_string(piece.original_colors["back"]) == to_string(side_colors["back"]));
        REQUIRE(to_string(piece.original_colors["left"]) == to_string(side_colors["left"]));
        REQUIRE(to_string(piece.original_colors["top"]) == to_string(side_colors["top"]));
      }
    }

    WHEN("piece its a front-top edge") {
      PieceColors piece(vec3(0, 2, 0), vec3(3, 3, 3));
      THEN("front and top colors should be set") {
        REQUIRE(to_string(piece.original_colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.original_colors["top"]) == to_string(side_colors["top"]));
      }
    }

    WHEN("piece its a front-bottom edge") {
      PieceColors piece(vec3(0, 0, 0), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.original_colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.original_colors["bottom"]) == to_string(side_colors["bottom"]));
      }
    }

    WHEN("piece its a front-left edge") {
      PieceColors piece(vec3(0, 1, 0), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.original_colors["front"]) == to_string(side_colors["front"]));
        REQUIRE(to_string(piece.original_colors["left"]) == to_string(side_colors["left"]));
      }
    }

    WHEN("piece its a back-right-bottom corner") {
      PieceColors piece(vec3(2, 0, -2), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.original_colors["back"]) == to_string(side_colors["back"]));
        REQUIRE(to_string(piece.original_colors["right"]) == to_string(side_colors["right"]));
        REQUIRE(to_string(piece.original_colors["bottom"]) == to_string(side_colors["bottom"]));
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

  WHEN("rotating on x axis (top right corner)") {
    THEN("should track the color rotation") {
      PieceColors piece(vec3(2, 2, 0), vec3(3, 3, 3));
      Move rMove("r");
      Move rPrimeMove("r'");

      REQUIRE(piece.colors == piece.original_colors);

      map<string, vec3> previous_colors = piece.colors;

      piece.rotate(rMove);
      REQUIRE(piece.colorNames["back"] == "yellow");
      REQUIRE(piece.colorNames["top"] == "red");

      previous_colors = piece.colors;
      piece.rotate(rMove);
      REQUIRE(piece.colorNames["back"] == "red");
      REQUIRE(piece.colorNames["bottom"] == "yellow");

      previous_colors = piece.colors;
      piece.rotate(rMove);
      REQUIRE(piece.colorNames["front"] == "yellow");
      REQUIRE(piece.colorNames["bottom"] == "red");

      previous_colors = piece.colors;
      piece.rotate(rMove);
      REQUIRE(piece.colors == piece.original_colors);
      REQUIRE(piece.colorNames["front"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      previous_colors = piece.colors;
      piece.rotate(rPrimeMove);
      REQUIRE(piece.colorNames["front"] == "yellow");
      REQUIRE(piece.colorNames["bottom"] == "red");

      previous_colors = piece.colors;
      piece.rotate(rPrimeMove);
      REQUIRE(piece.colorNames["bottom"] == "yellow");
      REQUIRE(piece.colorNames["back"] == "red");

      previous_colors = piece.colors;
      piece.rotate(rPrimeMove);
      REQUIRE(piece.colorNames["back"] == "yellow");
      REQUIRE(piece.colorNames["top"] == "red");

      previous_colors = piece.colors;
      piece.rotate(rPrimeMove);
      REQUIRE(piece.colorNames["top"] == "yellow");
      REQUIRE(piece.colorNames["front"] == "red");

      previous_colors = piece.colors;
      piece.rotate(rPrimeMove);
      piece.rotate(rMove);
      REQUIRE(piece.colorNames["top"] == "yellow");
      REQUIRE(piece.colorNames["front"] == "red");
    }
  }

  WHEN("rotating on y axis (top right corner)") {
    THEN("should track the color rotation") {
      PieceColors piece(vec3(2, 2, 0), vec3(3, 3, 3));
      Move tMove("t");
      Move tPrimeMove("t'");

      REQUIRE(piece.colors == piece.original_colors);

      map<string, vec3> previous_colors = piece.colors;

      piece.rotate(tMove);
      REQUIRE(piece.colorNames["front"] == "green");
      REQUIRE(piece.colorNames["left"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tMove);
      REQUIRE(piece.colorNames["back"] == "red");
      REQUIRE(piece.colorNames["left"] == "green");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tMove);
      REQUIRE(piece.colorNames["back"] == "green");
      REQUIRE(piece.colorNames["right"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tMove);
      REQUIRE(piece.colorNames["front"] == "red");
      REQUIRE(piece.colorNames["right"] == "green");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tPrimeMove);
      REQUIRE(piece.colorNames["back"] == "green");
      REQUIRE(piece.colorNames["right"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tPrimeMove);
      REQUIRE(piece.colorNames["left"] == "green");
      REQUIRE(piece.colorNames["back"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tPrimeMove);
      REQUIRE(piece.colorNames["front"] == "green");
      REQUIRE(piece.colorNames["left"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      piece.rotate(tPrimeMove);
      REQUIRE(piece.colorNames["right"] == "green");
      REQUIRE(piece.colorNames["front"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");

      previous_colors = piece.colors;
      piece.rotate(tPrimeMove);
      piece.rotate(tMove);
      REQUIRE(piece.colorNames["right"] == "green");
      REQUIRE(piece.colorNames["front"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");
    }
  }

  WHEN("rotating on z axis (top right corner)") {
    THEN("should track the color rotation") {
      PieceColors piece(vec3(2, 2, 0), vec3(3, 3, 3));
      Move fMove("f");
      Move fPrimeMove("f'");

      REQUIRE(piece.colors == piece.original_colors);

      map<string, vec3> previous_colors = piece.colors;

      piece.rotate(fMove);
      REQUIRE(piece.colorNames["bottom"] == "green");
      REQUIRE(piece.colorNames["right"] == "yellow");
      REQUIRE(piece.colorNames["front"] == "red");

      piece.rotate(fMove);
      REQUIRE(piece.colorNames["left"] == "green");
      REQUIRE(piece.colorNames["bottom"] == "yellow");

      piece.rotate(fMove);
      REQUIRE(piece.colorNames["top"] == "green");
      REQUIRE(piece.colorNames["left"] == "yellow");

      piece.rotate(fMove);
      REQUIRE(piece.colorNames["right"] == "green");
      REQUIRE(piece.colorNames["top"] == "yellow");

      previous_colors = piece.colors;
      piece.rotate(fPrimeMove);
      REQUIRE(piece.colorNames["top"] == "green");
      REQUIRE(piece.colorNames["left"] == "yellow");

      previous_colors = piece.colors;
      piece.rotate(fMove);
      piece.rotate(fPrimeMove);
      piece.rotate(fMove);
      REQUIRE(piece.colorNames["right"] == "green");
      REQUIRE(piece.colorNames["top"] == "yellow");
    }
  }

  WHEN("rotating on the 3 axis (top right corner)") {
    THEN("should track the color rotation") {
      PieceColors piece(vec3(2, 2, 0), vec3(3, 3, 3));
      Move fMove("f");
      Move rMove("r");
      Move tMove("t");
      Move tPrimeMove("t'");

      REQUIRE(piece.colors == piece.original_colors);

      map<string, vec3> previous_colors = piece.colors;

      piece.rotate(rMove);
      piece.rotate(tMove);
      piece.rotate(fMove);
      REQUIRE(piece.colorNames["bottom"] == "yellow");
      REQUIRE(piece.colorNames["right"] == "red");
      REQUIRE(piece.colorNames["front"] == "green");

      piece.rotate(rMove);
      REQUIRE(piece.colorNames["top"] == "green");
      REQUIRE(piece.colorNames["right"] == "red");
      REQUIRE(piece.colorNames["front"] == "yellow");

      piece.rotate(fMove);
      REQUIRE(piece.colorNames["right"] == "green");
      REQUIRE(piece.colorNames["bottom"] == "red");
      REQUIRE(piece.colorNames["front"] == "yellow");

      piece.rotate(rMove);
      piece.rotate(tPrimeMove);
      REQUIRE(piece.colorNames["back"] == "green");
      REQUIRE(piece.colorNames["right"] == "red");
      REQUIRE(piece.colorNames["top"] == "yellow");
    }
  }
}
