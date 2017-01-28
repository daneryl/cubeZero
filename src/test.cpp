// Include GLFW
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <iostream>
//extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#include "external/glm/glm/glm.hpp"
//#include "external/glm/gtc/matrix_transform.hpp"
using namespace glm;

#include "test.hpp"

glm::mat4 wtf;

glm::mat4 testMatrix(){
	return wtf;
}

glm::mat4 another;

glm::mat4 anotherMatrix(){
	return another;
}
