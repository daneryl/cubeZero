#include "../src/Piece.hpp"
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

  WHEN("rotatingon the x axis") {
    WHEN("CORNER"){
      THEN(".should move z and y axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3,3,3);
        Piece piece(vec3(0, 0, 0), puzzleSize);

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, 0.0)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, -2)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -2)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0)));
      }
      THEN(".should move z and y axis to the next position (5x5x5)") {
        vec3 puzzleSize = vec3(5,5,5);
        Piece piece(vec3(0, 0, 0), puzzleSize);

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 4, 0.0)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 4, -4)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -4)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, 0.0)));
      }
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

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 2, -1)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 1, -2)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 0, -1)));

        piece.rotate();
        REQUIRE(glm::to_string(piece.position) == glm::to_string(vec3(0, 1, 0)));
      }
    }
  }
}
