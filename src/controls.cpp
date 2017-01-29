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

#include "controls.hpp"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}


// Initial position : on +Z
glm::vec3 position = glm::vec3( 4, 3, 3 ); 
glm::vec3 direction = glm::vec3( 0, 0, 5 ); 
// Initial horizontal angle : toward -Z
float horizontalAngle = 9.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.05f;

int oldX, oldY;
bool rotate = false;
float theta =0, phi=0;


void computeMatricesFromInputs(GLFWwindow* window){

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double x, y;
	glfwGetCursorPos(window, &x, &y);
  //glfwSetCursorPos(window, (float)1024/2, (float)768/2);

	// Compute new orientation
    horizontalAngle += mouseSpeed * float(1024/2 - x );
	//verticalAngle   += mouseSpeed * float( 768/2 - y );
    verticalAngle   = 0.0f;

	// Reset mouse position for next frame


    float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

    ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

    float radius = 30.0f;
    float X = sin(theta) * radius;
    float Z = cos(theta) * radius;
    float Y = 14;

    ViewMatrix = glm::lookAt( glm::vec3(X, Y, Z), glm::vec3( 0, 0, 0 ), glm::vec3( 0, 1, 0 ));

    lastTime = currentTime;
    theta += (x-oldX)*0.01f;
    //phi   += (y-oldY)*0.1f;
    oldX = x; 
    oldY = y;
}
