cmake_minimum_required(VERSION 3.7)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(GLFW_SOURCE_DIR "external/glfw")
set(GLM_SOURCE_DIR "external/glm")

# Building only the GLFW lib
#set(BUILD_SHARED_LIBS OFF CACHE BOOL "")
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
#set(GLFW_INSTALL OFF CACHE BOOL "")

add_subdirectory(${GLFW_SOURCE_DIR} ${GLEW_SOURCE_DIR})

include_directories(${GLFW_SOURCE_DIR}/include
                    ${GLFW_SOURCE_DIR}/deps
                    ${GLM_SOURCE_DIR}
                    ${OPENGL_INCLUDE_DIRS}
                    ${GLUT_INCLUDE_DIRS}
                    ${GLEW_INCLUDE_DIRS})

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(cubeZero main.cpp ${SRC_FILES})
target_link_libraries(cubeZero glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

#add_executable(cubeZero main.cpp)

#if (APPLE)
  #set(APP_NAME CubeZero)

  ## if (EXISTS icon.icns)
    #add_executable(${APP_NAME} MACOSX_BUNDLE main.cpp)
    #set_source_files_properties("icon.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
  ## else ()
    ## add_executable(${APP_NAME} MACOSX_BUNDLE main.cpp)
  ## endif ()

  #target_link_libraries(${APP_NAME} glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} glew)
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_ICON_FILE "icon.icns")

  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME ${APP_NAME})
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
  #set_target_properties(${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_STRING "OpenGL boilerplate example app")
#endif()
