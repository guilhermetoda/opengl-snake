#include "snake.h"


Snake::Snake() 
{
    score = 0;
    // Creating the head of the snake
    SnakePart* head = new SnakePart();
    snakePieces.push_back(head);
}

Snake::~Snake() 
{

}