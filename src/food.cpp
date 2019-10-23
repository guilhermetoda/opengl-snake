#include "food.h"
#include "mathCompare.h"
#include <stdio.h>     /* srand, rand */

Food::Food(GLfloat x, GLfloat y) 
{
    xPosition = x;
    yPosition = y;
    srand((int)time(0));
}

Food::Food() 
{
    srand((int)time(0));
    GenerateNewFood();
}

void Food::GenerateNewFood() 
{   
    xPosition = GenerateRandomNumber(-100, 100);
    yPosition = GenerateRandomNumber(-100, 100);

    printf("Random: %f , %f\n", xPosition, yPosition);
}

float Food::GenerateRandomNumber(int min, int max) 
{
    if (min > max) 
    {
        return (float)max;
    }
    float r = (float)rand()/(float)RAND_MAX;

	return (min + r * (max - min)) / 100;
}