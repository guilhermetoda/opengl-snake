#include <glfw3.h>
#include <math.h>
#include "definitions.h"
#include "mathCompare.h"
#include "snake.h"
#include "food.h"
#include "draw.h"     /* srand, rand */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Draw d;
Food* food;
bool gameState = false;

bool checkLoseConditions(GLfloat x, GLfloat y) 
{

    if (x >= 1.0f || x<= -1.0f || y <= -1.0f || y >= 1.0f) 
    {
        
        return true;
    }
    return false;
}

void drawSnake(Snake* snake, GLfloat xFoward, GLfloat yFoward) 
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
}

void drawFood() 
{
    d.randomQuadDraw(food->xPosition, food->yPosition, 0.0f, 1.0f, 0.0f);
}

int main(void)
{
    GLFWwindow* window;
    Snake* snake;
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


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window) && !gameState)
    {

        // glfwGetTime is called only once, the first time this function is called
	    // Compute time difference between current and last frame
	    double currentTime = glfwGetTime();
	    float deltaTime = float(currentTime - lastTime);
        //printf ("Delta Time %f\n", deltaTime);
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearColor ( 0.1f, 0.1f, 0.1f, 1.0f );
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

        if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
            if (xPosition < 1.0f && snake->direction != LEFT) 
            {
                xFoward = speed;
                yFoward = 0.0f;
                snake->direction = RIGHT;
            }
	    }
	    // Strafe left
	    if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		    if (xPosition > -1.0f && snake->direction != RIGHT) 
            {
                xFoward = -speed;
                yFoward = 0.0f;
                snake->direction = LEFT;
            }
	    }
        if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		    if (yPosition < 1.0f && snake->direction != DOWN) 
            {
                xFoward = 0.0f;
                yFoward = speed;
                snake->direction = UP;
            }
	    }
	    // Move backward
	    if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		    if (yPosition > -1.0f && snake->direction != UP) 
            {
                xFoward = 0.0f;
                yFoward = -speed;
                snake->direction = DOWN;
            }
	    }
       
        drawFood();
        drawSnake(snake, xFoward, yFoward);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}