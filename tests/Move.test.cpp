#include "../src/Move.hpp"
#include "catch.hpp"
#include "glm/ext.hpp"

SCENARIO("Move", "[Move]") {

  WHEN("x axis") {
    THEN("r should initialize move properties as x axis, position2, angle -90") {
      Move move("r");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(1, 0, 0)));
      REQUIRE(move.axisPosition == 2);
      REQUIRE(move.angle == -90.0);
    }
    THEN("r' should initialize move properties as x axis, position2, angle 90") {
      Move move("r'");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(1, 0, 0)));
      REQUIRE(move.axisPosition == 2);
      REQUIRE(move.angle == 90.0);
    }

    THEN("l should initialize move properties as x axis, position0, angle 90") {
      Move move("l");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(1, 0, 0)));
      REQUIRE(move.axisPosition == 0);
      REQUIRE(move.angle == 90.0);
    }

    THEN("l' should initialize move properties as x axis, position0, angle -90") {
      Move move("l'");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(1, 0, 0)));
      REQUIRE(move.axisPosition == 0);
      REQUIRE(move.angle == -90.0);
    }
  }

  WHEN("y axis") {
    THEN("t should initialize move properties as y axis, position2, angle -90") {
      Move move("t");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 1, 0)));
      REQUIRE(move.axisPosition == 2);
      REQUIRE(move.angle == -90.0);
    }
    THEN("t' should initialize move properties as y axis, position2, angle 90") {
      Move move("t'");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 1, 0)));
      REQUIRE(move.axisPosition == 2);
      REQUIRE(move.angle == 90.0);
    }

    THEN("d should initialize move properties as y axis, position0, angle -90") {
      Move move("d");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 1, 0)));
      REQUIRE(move.axisPosition == 0);
      REQUIRE(move.angle == -90.0);
    }
    THEN("d' should initialize move properties as y axis, position0, angle 90") {
      Move move("d'");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 1, 0)));
      REQUIRE(move.axisPosition == 0);
      REQUIRE(move.angle == 90.0);
    }
  }

  WHEN("z axis") {
    THEN("f should initialize move properties as z axis, position0, angle -90") {
      Move move("f");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 0, 1)));
      REQUIRE(move.axisPosition == 0);
      REQUIRE(move.angle == -90.0);
    }
    THEN("f' should initialize move properties as z axis, position0, angle 90") {
      Move move("f'");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 0, 1)));
      REQUIRE(move.axisPosition == 0);
      REQUIRE(move.angle == 90.0);
    }
    THEN("b should initialize move properties as y axis, position2, angle -90") {
      Move move("b");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 0, 1)));
      REQUIRE(move.axisPosition == -2);
      REQUIRE(move.angle == -90.0);
    }
    THEN("b' should initialize move properties as y axis, position2, angle 90") {
      Move move("b'");

      REQUIRE(glm::to_string(move.axis) == glm::to_string(vec3(0, 0, 1)));
      REQUIRE(move.axisPosition == -2);
      REQUIRE(move.angle == 90.0);
    }
  }
}
