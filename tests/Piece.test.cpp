#include "../src/Piece.hpp"
#include "../src/Move.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"

using namespace constants;

SCENARIO("Piece", "[Piece]") {

  WHEN("instantiating") {
    THEN("should initialize position") {
      vec3 position = vec3(1, 1, 1);
      vec3 puzzleSize = vec3(3,3,3);
      Piece piece(position, puzzleSize);
      REQUIRE(glm::to_string(piece.position) == glm::to_string(position));
      REQUIRE(glm::to_string(piece.puzzleSize) == glm::to_string(puzzleSize));
    }
  }

  WHEN("rotating on the y axis") {
    WHEN("CORNER"){
      THEN("should move z and x axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3, 3, 3);
        Piece piece(vec3(0, 2, 0), puzzleSize);

        Move tMove("t");
        Move tPrimeMove("t'");

        piece.rotate(tMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, -2)));

        piece.rotate(tPrimeMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, 0.0)));

        piece.rotate(tMove);
        piece.rotate(tMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(2, 2, -2)));

        piece.rotate(tMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(2, 2, 0)));

        piece.rotate(tMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, 0.0)));
      }
    }
  }

  WHEN("rotating on the z axis") {
    WHEN("CORNER"){
      THEN("should move y and x axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3, 3, 3);
        Piece piece(vec3(0, 0, 0), puzzleSize);

        Move fMove("f");
        Move fPrimeMove("f'");

        piece.rotate(fMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, 0)));

        piece.rotate(fPrimeMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0)));

        piece.rotate(fMove);
        piece.rotate(fMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(2, 2, 0)));

        piece.rotate(fMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(2, 0, 0)));

        piece.rotate(fMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0)));
      }
    }
  }

  WHEN("rotating on the x axis") {
    WHEN("CORNER"){
      THEN("should move z and y axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3, 3, 3);
        Piece piece(vec3(0, 0, 0), puzzleSize);

        Move rMove("r");
        Move rPrimeMove("r'");

        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, 0.0)));

        piece.rotate(rPrimeMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0)));

        piece.rotate(rMove);
        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, -2)));

        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -2)));

        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0)));
      }
      /* THEN(".should move z and y axis to the next position (5x5x5)") { */
      /*   vec3 puzzleSize = vec3(5,5,5); */
      /*   Piece piece(vec3(0, 0, 0), puzzleSize); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 4, 0.0))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 4, -4))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -4))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0))); */
      /* } */
      /* THEN("should move z and y axis to the next position (2x2x2)") { */
      /*   vec3 puzzleSize = vec3(4,4,4); */
      /*   Piece piece(vec3(0, 0, 0), puzzleSize); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 3, 0.0))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 3, -3))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -3))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0))); */
      /* } */
      /* THEN("should move z and y axis to the next position (4x4x4)") { */
      /*   vec3 puzzleSize = vec3(4,4,4); */
      /*   Piece piece(vec3(0, 0, 0), puzzleSize); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 3, -0.0))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 3, -3))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -3))); */

      /*   piece.rotate(); */
      /*   REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0))); */
      /* } */
    }
    WHEN("EDGE"){
      THEN(".should move z and y axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3,3,3);
        Piece piece(vec3(0, 1 ,0), puzzleSize);

        Move rMove("r");
        Move rPrimeMove("r'");

        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, -1)));

        piece.rotate(rPrimeMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 1, 0)));

        piece.rotate(rMove);
        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 1, -2)));

        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -1)));

        piece.rotate(rMove);
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 1, 0)));
      }
    }
  }
}
