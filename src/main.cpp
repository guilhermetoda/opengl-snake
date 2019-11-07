#include <glfw3.h>
#include <math.h>
#include "definitions.h"
#include "mathCompare.h"
#include "snake.h"
#include "food.h"
#include "draw.h"     /* srand, rand */
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <time.h>       /* time */

Draw d;
Food* food;
Snake* snake;
bool gameState = false;

bool checkLoseConditions(GLfloat x, GLfloat y) 
{

    if (x >= 1.0f || x<= -1.0f || y <= -1.0f || y >= 1.0f) 
    {
        
        return true;
    }
    return false;
}

//Deque version
void drawSnake(GLfloat xFoward, GLfloat yFoward)
{
    GLfloat newX = snake->head->xPosition + xFoward;
    GLfloat newY = snake->head->yPosition + yFoward;
    // Removing last piece
    d.quadDrawWithSize(snake->snakePieces.back()->xPosition, snake->snakePieces.back()->yPosition, 0.04f, 0.04f);
    snake->moveSnake(newX, newY);
    d.quadDraw(snake->head->xPosition, snake->head->yPosition, 1.0f, 1.0f, 1.0f);
    
    if (MathLib::Compare(snake->head->xPosition, food->xPosition) && MathLib::Compare(snake->head->yPosition, food->yPosition)) 
    {
        // Removing Food from the screen
        d.quadDrawWithSize(food->xPosition, food->yPosition, 0.05f, 0.05f);

        SnakePart* newPiece = snake->snakePieces.back();
        d.quadDraw(snake->snakePieces.back()->xPosition, snake->snakePieces.back()->yPosition, 1.0f, 1.0f, 1.0f);
        snake->snakePieces.push_back(newPiece);
        snake->score++;
        food->GenerateNewFood();
    }
    if (checkLoseConditions(snake->head->xPosition, snake->head->yPosition)) 
    {
        std::cout << "Snake with Deque \n";
        std::cout << "GAME IS OVER!\n";
        std::cout << "Your score is: "<< snake->score << "\n";
        gameState = true;

    }
}

/*void drawSnake(GLfloat xFoward, GLfloat yFoward) 
{
    for (int i = snake->snakePieces.size() - 1; i >= 0 ; i--)
    {
        if (i == 0) 
        {
            snake->snakePieces[0]->xPosition = snake->snakePieces[0]->xPosition + xFoward;
            snake->snakePieces[0]->yPosition = snake->snakePieces[0]->yPosition + yFoward;
            d.randomQuadDraw(snake->snakePieces[0]->xPosition, snake->snakePieces[0]->yPosition, 1.0f, 0.0f, 0.0f);
             //printf("%f - %f \n", snake->snakePieces[0]->xPosition, snake->snakePieces[0]->yPosition);
            if (MathLib::Compare(snake->snakePieces[0]->xPosition, food->xPosition) && MathLib::Compare(snake->snakePieces[0]->yPosition, food->yPosition)) 
            {
                snake->snakePieces.push_back(new SnakePart());
                snake->score++;
                food->GenerateNewFood();
            }
            if (checkLoseConditions(snake->snakePieces[0]->xPosition, snake->snakePieces[0]->yPosition)) 
            {
                printf("GAME IS OVER!\n");
                printf("Your score is: %d\n", snake->score);
                gameState = true;

            }
            
        }
        else 
        {
            snake->snakePieces[i]->xPosition = snake->snakePieces[i - 1]->xPosition;
            snake->snakePieces[i]->yPosition = snake->snakePieces[i - 1]->yPosition;
            d.randomQuadDraw(snake->snakePieces[i]->xPosition, snake->snakePieces[i]->yPosition, 1.0f, 1.0f, 1.0f);
        }
    } 
}*/

void drawFood() 
{
    d.quadDraw(food->xPosition, food->yPosition, 0.0f, 1.0f, 0.0f);
}

int main(void)
{
    GLFWwindow* window;
    
    snake = new Snake();
    food = new Food();

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "The Snake Game!", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	glfwSwapInterval( 1 );

	// set up view
	//glViewport( 0, 0, 400, 400 );
    glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
    
    
    float xPosition = 0.0f;
    float yPosition = 0.0f;
    double lastTime = glfwGetTime();
    float speed = 0.015f;
    GLfloat xFoward = 0.0f;
    GLfloat yFoward = 0.0f;

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor ( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window) && !gameState)
    {

        // glfwGetTime is called only once, the first time this function is called
	    // Compute time difference between current and last frame
	    double currentTime = glfwGetTime();
	    float deltaTime = float(currentTime - lastTime);
        //printf ("Delta Time %f\n", deltaTime);
        /* Render here */
        

        if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
            if (xPosition < 1.0f && snake->direction != Definitions::left) 
            {
                xFoward = speed;
                yFoward = 0.0f;
                snake->direction = Definitions::right;
            }
	    }
	    // Strafe left
	    if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		    if (xPosition > -1.0f && snake->direction != Definitions::right) 
            {
                xFoward = -speed;
                yFoward = 0.0f;
                snake->direction = Definitions::left;
            }
	    }
        if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		    if (yPosition < 1.0f && snake->direction != Definitions::down) 
            {
                xFoward = 0.0f;
                yFoward = speed;
                snake->direction = Definitions::up;
            }
	    }
	    // Move backward
	    if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		    if (yPosition > -1.0f && snake->direction != Definitions::up) 
            {
                xFoward = 0.0f;
                yFoward = -speed;
                snake->direction = Definitions::down;
            }
	    }
       
        drawFood();
        drawSnake(xFoward, yFoward);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}