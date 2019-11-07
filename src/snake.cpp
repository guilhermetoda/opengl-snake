#include "snake.h"


Snake::Snake() 
{
    score = 0;
    // Creating the head of the snake
    SnakePart* first = new SnakePart();
    snakePieces.push_back(first);
    //pointing head to the first piece
    head = snakePieces[0];
}

void Snake::moveSnake(GLfloat newX, GLfloat newY) 
{
    if (!snakePieces.empty()) 
    {
        // Remove Last element from the vector
        snakePieces.pop_back();
        //tail = snakePieces[snakePieces.size()];
        snakePieces.push_front(new SnakePart(newX, newY));
        head = snakePieces.front();
    }
}