#include <glfw3.h>
#include <stdio.h>     /* srand, rand */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Draw
{
    public:
        Draw();
        void quadDraw(GLfloat x, GLfloat y, GLfloat R =0.0f, GLfloat G = 0.0f, GLfloat B = 0.0f);
        void quadDrawWithSize(GLfloat x, GLfloat y, GLfloat sizeX, GLfloat sizeY, GLfloat R =0.0f, GLfloat G = 0.0f, GLfloat B = 0.0);
        float randQuadSize();
        void GetDirection();
        void increaseSnakeSize();
        void glfwKeyCallback();
        void DrawSquare(GLfloat x, GLfloat y);

    private:
        float movingIndex = 0.0f;
        float xPosition = 0.0f;
        GLfloat xSize = 0.0f;
        GLfloat ySize = 0.0f;
        const GLfloat startingSize = 0.02f;
};