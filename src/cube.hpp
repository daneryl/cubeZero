#ifndef CUBE_H
#define CUBE_H

class Cube
{
    private:
        glm::mat4 model;
        GLuint cubeBuffer;
        GLuint MatrixID;
    public:
        static const GLfloat vertexList[108];
        Cube(glm::mat4 translation, GLuint matID);
        void draw(glm::mat4 projection, glm::mat4 view);
};
#endif
