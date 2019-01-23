#include "../src/Piece.hpp"
#include "../src/Move.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"

using namespace constants;

SCENARIO("Piece", "[Piece]") {

  WHEN("instantiating") {
    THEN("should initialize position") {
      vec3 position = vec3(1, 2, 3);
      vec3 puzzleSize = vec3(3,3,3);
      Piece piece(position, puzzleSize);

      REQUIRE(piece.position.x == 1);
      REQUIRE(piece.position.y == 2);
      REQUIRE(piece.position.z == 3);
      REQUIRE(glm::to_string(piece.position.puzzleSize) == glm::to_string(puzzleSize));
      REQUIRE(glm::to_string(piece.puzzleSize) == glm::to_string(puzzleSize));
    }
  }

  WHEN("rotate") {
    THEN("should rotate position") {
      vec3 position = vec3(2, 0, 0);
      vec3 puzzleSize = vec3(3,3,3);
      Move rMove("r");

      Piece piece(position, puzzleSize);

      piece.rotate(rMove);
      REQUIRE(piece.position.x == 2);
      REQUIRE(piece.position.y == 2);
      REQUIRE(piece.position.z == 0);
    }
  }
}
