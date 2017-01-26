// Include GLFW
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <iostream>
//extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
	//horizontalAngle += mouseSpeed * float(1024/2 - x );
	//verticalAngle   += mouseSpeed * float( 768/2 - y );
	//verticalAngle   = 0.0f;

	// Reset mouse position for next frame

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	//glm::vec3 direction(
		//cos(verticalAngle) * sin(horizontalAngle), 
		//sin(verticalAngle),
		//cos(verticalAngle) * cos(horizontalAngle)
	//);
	
	
	//// Up vector
	//glm::vec3 up = glm::cross( right, direction );

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

  //print(horizontalAngle);
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
    glm::rotate(glm::mat4(), 0.5f, glm::vec3(0, 1, 0));
    //glm::translate(glm::mat4(), glm::vec3(2+horizontalAngle, 0, 0))*

	//if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		//position -= right * deltaTime * speed;
	//}
	// Camera matrix
	//ViewMatrix       = glm::lookAt(
								//position,           // Camera is here
								//position+direction, // and looks here : at the same position, plus "direction"
								//up                  // Head is up (set to 0,-1,0 to look upside-down)
							 //);

  float eyeX = 6*cos(phi)*sin(theta);
  float eyeY = 6*sin(phi)*sin(theta);
  float eyeZ = 6*cos(theta);

  ViewMatrix = 
    //glm::rotate(glm::mat4(), 0.5f, glm::vec3(0, 1, 0)) * 
    glm::lookAt( glm::vec3(eyeX, eyeY, eyeZ), glm::vec3( 0, 0, 0 ), glm::vec3( 0, 1, 0 ));
	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;

  theta += (x-oldX)*0.01f;
  phi   += (y-oldY)*0.01f;
  oldX = x; 
  oldY = y;
}
