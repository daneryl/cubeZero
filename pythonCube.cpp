#include <pybind11/pybind11.h>
#include "src/PieceColors.hpp"
#include <glm/glm.hpp>
#include "src/OpenGL.hpp"


string initCube() {
  OpenGL::init();
  PieceColors piece(glm::vec3(0, 0, 0), glm::vec3(3, 3, 3));
  return piece.colorNames["front"];
}

PYBIND11_MODULE(pythonCube, m) {
  m.doc() = "pybind11 test plugin"; // optional module docstring

  m.def("initCube", &initCube, "A function which adds two numbers");
}
