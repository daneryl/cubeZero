cmake_minimum_required(VERSION 3.7)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(GLFW_SOURCE_DIR "external/glfw")
set(GLM_SOURCE_DIR "external/glm")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${GLFW_SOURCE_DIR} ${GLEW_SOURCE_DIR})

include_directories(
  ${GLFW_SOURCE_DIR}/include
  ${GLFW_SOURCE_DIR}/deps
  ${GLM_SOURCE_DIR}
  ${OPENGL_INCLUDE_DIRS}
  ${GLUT_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB OPEN_GL ${PROJECT_SOURCE_DIR}/src/OpenGL/OpenGL.cpp)

add_executable(cubeZero main.cpp  ${OPEN_GL} ${SRC_FILES})
target_link_libraries(cubeZero glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

option(BUILD_TESTS "Determines whether to build tests." OFF)

if(BUILD_TESTS)
  set(CATCH_INCLUDE_DIR "external/Catch")
  add_library(Catch INTERFACE)
  target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

  file(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)
  file(GLOB MOCK_OPEN_GL ${PROJECT_SOURCE_DIR}/src/OpenGL/OpenGLMock.cpp)
  add_executable(tests ${MOCK_OPEN_GL} ${TEST_FILES} ${SRC_FILES})
  target_link_libraries(tests Catch glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})
endif()
