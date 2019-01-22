#define private public

#include "../src/puzzle.hpp"
#include "glm/ext.hpp"
#include "catch.hpp"
#include <GL/glew.h>


SCENARIO("Puzzle", "[Puzzle]") {
  GIVEN("Given PiecePosition and maxPieces") {
    THEN("should build a 27 pieces puzzle") {
      Puzzle rubik = Puzzle(3, 3, 3);
      REQUIRE(rubik.pieces.size() == 27);
    }
  }

  WHEN("state") {
    GIVEN("initial state") {
      THEN("should return a map with all faces colors") {
        Puzzle puzzle = Puzzle(3, 3, 3);
        map<string, vector<vector<string>>> state = puzzle.state();

        vector<vector<string>> expectedFront = {
          {"red", "red", "red"},
          {"red", "red", "red"},
          {"red", "red", "red"}
        };

        REQUIRE(state["front"] == expectedFront);

        vector<vector<string>> expectedBack = {
          {"orange", "orange", "orange"},
          {"orange", "orange", "orange"},
          {"orange", "orange", "orange"}
        };

        REQUIRE(state["back"] == expectedBack);

        vector<vector<string>> expectRight = {
          {"green", "green", "green"},
          {"green", "green", "green"},
          {"green", "green", "green"}
        };

        REQUIRE(state["right"] == expectRight);

        vector<vector<string>> expectLeft = {
          {"blue", "blue", "blue"},
          {"blue", "blue", "blue"},
          {"blue", "blue", "blue"}
        };

        REQUIRE(state["left"] == expectLeft);

        vector<vector<string>> expectTop = {
          {"yellow", "yellow", "yellow"},
          {"yellow", "yellow", "yellow"},
          {"yellow", "yellow", "yellow"}
        };

        REQUIRE(state["top"] == expectTop);

        vector<vector<string>> expectBottom = {
          {"white", "white", "white"},
          {"white", "white", "white"},
          {"white", "white", "white"}
        };

        REQUIRE(state["bottom"] == expectBottom);
      }
    }
    
    GIVEN("r Move") {
      THEN("should return a map with right faces rotated") {
        Puzzle puzzle = Puzzle(3, 3, 3);
        puzzle.move("r");

        map<string, vector<vector<string>>> state = puzzle.state();
        vector<vector<string>> expectedFront = {
          {"red", "red", "white"},
          {"red", "red", "white"},
          {"red", "red", "white"}
        };

        REQUIRE(state["front"] == expectedFront);

        vector<vector<string>> expectedBack = {
          {"yellow", "orange", "orange"},
          {"yellow", "orange", "orange"},
          {"yellow", "orange", "orange"}
        };

        REQUIRE(state["back"] == expectedBack);

        vector<vector<string>> expectedTop = {
          {"yellow", "yellow", "red"},
          {"yellow", "yellow", "red"},
          {"yellow", "yellow", "red"}
        };

        REQUIRE(state["top"] == expectedTop);

        vector<vector<string>> expectBottom = {
          {"white", "white", "orange"},
          {"white", "white", "orange"},
          {"white", "white", "orange"}
        };

        REQUIRE(state["bottom"] == expectBottom);
      }
    }

    GIVEN("f Move") {
      THEN("should return a map with right faces rotated") {
        Puzzle puzzle = Puzzle(3, 3, 3);
        puzzle.move("f");

        map<string, vector<vector<string>>> state = puzzle.state();
        vector<vector<string>> expectedTop = {
          {"yellow", "yellow", "yellow"},
          {"yellow", "yellow", "yellow"},
          {"blue", "blue", "blue"},
        };

        REQUIRE(state["top"] == expectedTop);

        vector<vector<string>> expectLeft = {
          {"blue", "blue", "white"},
          {"blue", "blue", "white"},
          {"blue", "blue", "white"},
        };

        REQUIRE(state["left"] == expectLeft);

        vector<vector<string>> expectRight = {
          {"yellow", "green", "green"},
          {"yellow", "green", "green"},
          {"yellow", "green", "green"},
        };

        REQUIRE(state["right"] == expectRight);

        vector<vector<string>> expectBottom = {
          {"green", "green", "green"},
          {"white", "white", "white"},
          {"white", "white", "white"},
        };

        REQUIRE(state["bottom"] == expectBottom);
      }
    }

    GIVEN("a combination of movements") {
      THEN("should return a map with right faces rotated") {
        Puzzle puzzle = Puzzle(3, 3, 3);
        puzzle.move("f");
        puzzle.move("r");
        puzzle.move("u");
        puzzle.move("f'");

        /* map<string, vector<vector<string>>> state = puzzle.state(); */
        /* vector<vector<string>> expectedTop = { */
        /*   {"blue", "yellow", "yellow"}, */
        /*   {"blue", "yellow", "yellow"}, */
        /*   {"blue", "green", "green"}, */
        /* }; */

        /* REQUIRE(state["top"] == expectedTop); */

        /* vector<vector<string>> expectFront = { */
        /*   {"yellow", "white", "white"}, */
        /*   {"yellow", "red", "red"}, */
        /*   {"yellow", "red", "red"}, */
        /* }; */

        /* REQUIRE(state["front"] == expectFront); */

        /* vector<vector<string>> expectRight = { */
        /*   {"orange", "orange", "orange"}, */
        /*   {"green", "green", "green"}, */
        /*   {"green", "green", "green"}, */
        /* }; */

        /* REQUIRE(state["right"] == expectRight); */

        /* vector<vector<string>> expectLeft = { */
        /*   {"red", "red", "green"}, */
        /*   {"blue", "blue", "white"}, */
        /*   {"blue", "blue", "white"}, */
        /* }; */

        /* REQUIRE(state["left"] == expectLeft); */

        /* vector<vector<string>> expectBottom = { */
        /*   {"green", "green", "orange"}, */
        /*   {"white", "white", "orange"}, */
        /*   {"white", "white", "orange"}, */
        /* }; */

        /* REQUIRE(state["bottom"] == expectBottom); */

        /* vector<vector<string>> expectBack = { */
        /*   {"blue", "blue", "white"}, */
        /*   {"yellow", "orange", "orange"}, */
        /*   {"yellow", "orange", "orange"}, */
        /* }; */

        /* REQUIRE(state["back"] == expectBack); */
      }
    }
  }
}
