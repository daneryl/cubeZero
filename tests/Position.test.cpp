#include "../src/Position.hpp"
#include "../src/Move.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"

using namespace constants;

string position_string(Position position) {
  return to_string(position.x) + ", " + to_string(position.y) + ", " + to_string(position.z);
}

string position_string(vec3 position) {
  return to_string(int(position.x)) + ", " + to_string(int(position.y)) + ", " + to_string(int(position.z));
}

SCENARIO("Position", "[Position]") {

  WHEN("instantiating") {
    THEN("should initialize coordinates") {
      vec3 coordinates = vec3(1, 2, 3);
      vec3 puzzleSize = vec3(3,3,3);
      Position position(coordinates, puzzleSize);
      REQUIRE(position.x == 1);
      REQUIRE(position.y == 2);
      REQUIRE(position.z == 3);
      REQUIRE(glm::to_string(position.puzzleSize) == glm::to_string(puzzleSize));
    }
  }

  WHEN("rotating on the y axis") {
    WHEN("CORNER"){
      THEN("should move z and x axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3, 3, 3);
        Position position(vec3(0, 2, 0), puzzleSize);

        Move uMove("u");
        Move uPrimeMove("u'");

        position.rotate(uMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, -2)));

        position.rotate(uPrimeMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, 0)));

        position.rotate(uMove);
        position.rotate(uMove);
        REQUIRE(position_string(position) == position_string(vec3(2, 2, -2)));

        position.rotate(uMove);
        REQUIRE(position_string(position) == position_string(vec3(2, 2, 0)));

        position.rotate(uMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, 0)));
      }
    }
  }

  WHEN("rotating on the z axis") {
    WHEN("CORNER"){
      THEN("should move y and x axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3, 3, 3);
        Position position(vec3(0, 0, 0), puzzleSize);

        Move fMove("f");
        Move fPrimeMove("f'");

        position.rotate(fMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, 0)));

        position.rotate(fPrimeMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 0, 0)));

        position.rotate(fMove);
        position.rotate(fMove);
        REQUIRE(position_string(position) == position_string(vec3(2, 2, 0)));

        position.rotate(fMove);
        REQUIRE(position_string(position) == position_string(vec3(2, 0, 0)));

        position.rotate(fMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 0, 0)));
      }
    }
  }

  WHEN("rotating on the x axis") {
    WHEN("CORNER"){
      THEN("should move z and y axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3, 3, 3);
        Position position(vec3(0, 0, 0), puzzleSize);

        Move rMove("r");
        Move rPrimeMove("r'");

        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, 0)));

        position.rotate(rPrimeMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 0, 0)));

        position.rotate(rMove);
        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, -2)));

        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 0, -2)));

        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 0, 0)));
      }
      /* THEN(".should move z and y axis to the next position (5x5x5)") { */
      /*   vec3 puzzleSize = vec3(5,5,5); */
      /*   Position position(vec3(0, 0, 0), puzzleSize); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 4, 0.0))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 4, -4))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 0, -4))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 0, 0.0))); */
      /* } */
      /* THEN("should move z and y axis to the next position (2x2x2)") { */
      /*   vec3 puzzleSize = vec3(4,4,4); */
      /*   Position position(vec3(0, 0, 0), puzzleSize); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 3, 0.0))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 3, -3))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 0, -3))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 0, 0.0))); */
      /* } */
      /* THEN("should move z and y axis to the next position (4x4x4)") { */
      /*   vec3 puzzleSize = vec3(4,4,4); */
      /*   Position position(vec3(0, 0, 0), puzzleSize); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 3, -0.0))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 3, -3))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 0, -3))); */

      /*   position.rotate(); */
      /*   REQUIRE(glm::to_string(position.position) == glm::to_string(vec3(0, 0, 0.0))); */
      /* } */
    }
    WHEN("EDGE"){
      THEN(".should move z and y axis to the next position (3x3x3)") {
        vec3 puzzleSize = vec3(3,3,3);
        Position position(vec3(0, 1 ,0), puzzleSize);

        Move rMove("r");
        Move rPrimeMove("r'");

        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 2, -1)));

        position.rotate(rPrimeMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 1, 0)));

        position.rotate(rMove);
        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 1, -2)));

        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 0, -1)));

        position.rotate(rMove);
        REQUIRE(position_string(position) == position_string(vec3(0, 1, 0)));
      }
    }
  }
}
