#include <glfw3.h>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Food 
{
    public:
        GLfloat xPosition;
        GLfloat yPosition;

        Food(GLfloat x, GLfloat y);
        Food();
        void GenerateNewFood();
        float GenerateRandomNumber(int min, int max);
};