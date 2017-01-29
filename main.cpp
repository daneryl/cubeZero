#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <GL/glew.h>

#include <GLFW/glfw3.h>
//Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//using namespace glm;

#include "src/shader.h"
#include "src/controls.hpp"
#include "src/cube.hpp"

#define GLSL(src) #src

int main( void )
{
    GLFWwindow *window;
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 1024, 768, "Tutorial 02 - Red triangle", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(window);

    // hide triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    //Cube cube = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 2.2f, 0.0f)));

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders( "vertex.shader", "fragment.shader" );


    // Get a handle for our "MVP" uniform
    // Only during the initialisation
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");
    //GLuint MatrixID2 = glGetUniformLocation(programID, "MVP2");
    //GLuint MatrixID2 = glGetUniformLocation(programID, "MVP2");
    //
    static GLfloat g_color_buffer_data[12*3*3];

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // This is done in the main loop since each model will have a different MVP matrix (At least for the M part)

    printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);

    Cube *cube = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)), MatrixID);
    Cube *cube2 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, 2.2f, 0.0f)), MatrixID);
    Cube *cube3 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, -2.2f, 0.0f)), MatrixID);
    Cube *cube4 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, 0.0f, 0.0f)), MatrixID);
    Cube *cube5 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -2.2f, 0.0f)), MatrixID);
    Cube *cube6 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, -2.2f, 0.0f)), MatrixID);
    Cube *cube7 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, 0.0f, 0.0f)), MatrixID);
    Cube *cube8 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 2.2f, 0.0f)), MatrixID);
    Cube *cube9 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, 2.2f, 0.0f)), MatrixID);

    Cube *cube10 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 2.2f)), MatrixID);
    Cube *cube11 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, 2.2f, 2.2f)), MatrixID);
    Cube *cube12 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, -2.2f, 2.2f)), MatrixID);
    Cube *cube13 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, 0.0f, 2.2f)), MatrixID);
    Cube *cube14 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -2.2f, 2.2f)), MatrixID);
    Cube *cube15 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, -2.2f, 2.2f)), MatrixID);
    Cube *cube16 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, 0.0f, 2.2f)), MatrixID);
    Cube *cube17 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 2.2f, 2.2f)), MatrixID);
    Cube *cube18 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, 2.2f, 2.2f)), MatrixID);

    Cube *cube19 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.2f)), MatrixID);
    Cube *cube20 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, 2.2f, -2.2f)), MatrixID);
    Cube *cube21 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, -2.2f, -2.2f)), MatrixID);
    Cube *cube22 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, 0.0f, -2.2f)), MatrixID);
    Cube *cube23 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -2.2f, -2.2f)), MatrixID);
    Cube *cube24 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, -2.2f, -2.2f)), MatrixID);
    Cube *cube25 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(2.2f, 0.0f, -2.2f)), MatrixID);
    Cube *cube26 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 2.2f, -2.2f)), MatrixID);
    Cube *cube27 = new Cube(glm::translate(glm::mat4(1.0f), glm::vec3(-2.2f, 2.2f, -2.2f)), MatrixID);

    glUseProgram(programID);

    do{
        // Enable depth test
        glEnable(GL_DEPTH_TEST);
        // Accept fragment if it closer to the camera than the former one
        glDepthFunc(GL_LESS);
        // Clear the screen
        //glClear( GL_COLOR_BUFFER_BIT );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

        computeMatricesFromInputs(window);
        glm::mat4 Projection = getProjectionMatrix();
        glm::mat4 View = getViewMatrix();
        // Use our shader

        //srand (static_cast <unsigned> (time(0)));
        for (int v = 0; v < 12*3 ; v++) {
            g_color_buffer_data[3*v+0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            g_color_buffer_data[3*v+1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            g_color_buffer_data[3*v+2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        }


        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                3,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
                );

        glEnableVertexAttribArray(0);

        cube->draw(Projection, View);
        cube2->draw(Projection, View);
        cube3->draw(Projection, View);
        cube4->draw(Projection, View);
        cube5->draw(Projection, View);
        cube6->draw(Projection, View);
        cube7->draw(Projection, View);
        cube8->draw(Projection, View);
        cube9->draw(Projection, View);

        cube10->draw(Projection, View);
        cube11->draw(Projection, View);
        cube12->draw(Projection, View);
        cube13->draw(Projection, View);
        cube14->draw(Projection, View);
        cube15->draw(Projection, View);
        cube16->draw(Projection, View);
        cube17->draw(Projection, View);
        cube18->draw(Projection, View);

        cube19->draw(Projection, View);
        cube20->draw(Projection, View);
        cube21->draw(Projection, View);
        cube22->draw(Projection, View);
        cube23->draw(Projection, View);
        cube24->draw(Projection, View);
        cube25->draw(Projection, View);
        cube26->draw(Projection, View);
        cube27->draw(Projection, View);

        //glDisableVertexAttribArray(0);
        //glDisableVertexAttribArray(1);
        //glDisableVertexAttribArray(2);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0 );

    // Cleanup VBO
    //glDeleteBuffers(1, &cubeBuffer);
    //glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

