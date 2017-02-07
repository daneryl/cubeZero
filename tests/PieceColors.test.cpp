#include "../src/PieceColors.hpp"
#include "../src/CubeVertexInfo.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"

SCENARIO("PieceColors", "[PieceColors]") {
  GIVEN("Given PiecePosition and maxPieces") {

    //WHEN("piece its in the front") {
      //PieceColors piece(vec3(3, 0, 0), vec3(3, 3, 3));
      //THEN("front colors should be set") {
        //REQUIRE(to_string(piece.colors["front"]) == to_string(SIDE_COLORS["front"]));
      //}
    //}

    WHEN("piece its a back-top edge") {
      PieceColors piece(vec3(3, 3, 0), vec3(3, 3, 3));
      THEN("front and top colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(SIDE_COLORS["front"]));
        REQUIRE(to_string(piece.colors["top"]) == to_string(SIDE_COLORS["top"]));
      }
    }

    WHEN("piece its a front-top edge") {
      PieceColors piece(vec3(3, 3, 0), vec3(3, 3, 3));
      THEN("front and top colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(SIDE_COLORS["front"]));
        REQUIRE(to_string(piece.colors["top"]) == to_string(SIDE_COLORS["top"]));
      }
    }

    WHEN("piece its a front-bottom edge") {
      PieceColors piece(vec3(3, 1, 1), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(SIDE_COLORS["front"]));
        REQUIRE(to_string(piece.colors["bottom"]) == to_string(SIDE_COLORS["bottom"]));
      }
    }

    WHEN("piece its a front-left edge") {
      PieceColors piece(vec3(3, 1, 3), vec3(3, 3, 3));
      THEN("front and bottom colors should be set") {
        REQUIRE(to_string(piece.colors["front"]) == to_string(SIDE_COLORS["front"]));
        REQUIRE(to_string(piece.colors["left"]) == to_string(SIDE_COLORS["left"]));
      }
    }
  }
}

// TEST_CASE( "Factorials are not computed", "[factorial]" ) {
// REQUIRE( Factorial(1) == 1 );
// REQUIRE( Factorial(2) == 2 );
// REQUIRE( Factorial(3) == 6 );
// REQUIRE( Factorial(10) == 3628800 );
//}
