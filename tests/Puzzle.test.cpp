#define private public

#include "../src/puzzle.hpp"
//#include "../src/cube.hpp"
//#include "../src/PieceColors.hpp"
//#include "../src/CubeVertexInfo.hpp"
#include "glm/ext.hpp"
#include "catch.hpp"
#include <GL/glew.h>
//#include "fakeit.hpp"


//using namespace fakeit;
//using namespace constants;

SCENARIO("Puzzle", "[Puzzle]") {
  GIVEN("Given PiecePosition and maxPieces") {
    WHEN("piece its in the front") {

      THEN("front colors should be set and all other colors should be black") {
        Puzzle rubik = Puzzle(3, 3, 3);

        //cout << rubik.cubes.size() << std::endl;
        REQUIRE(rubik.cubes.size() == 27);

        //Mock<Puzzle> mock;
      //SomeClass& i = spy.get();
        //REQUIRE(to_string(piece.colors["front"]) == to_string(side_colors["front"]));
        //REQUIRE(to_string(piece.colors["bottom"]) == to_string(base_side_colors["bottom"]));
        //REQUIRE(to_string(piece.colors["top"]) == to_string(base_side_colors["top"]));
        //REQUIRE(to_string(piece.colors["left"]) == to_string(base_side_colors["left"]));
        //REQUIRE(to_string(piece.colors["right"]) == to_string(base_side_colors["right"]));
        //REQUIRE(to_string(piece.colors["back"]) == to_string(base_side_colors["back"]));
      }
    }
  }
}
