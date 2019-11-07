#include "snakePart.h"
#include <glfw3.h>
#include <deque>

class Snake 
{
    public:
        int direction;
        int score;
        SnakePart* head;
        //std::vector<SnakePart*> snakePieces;
        std::deque<SnakePart*> snakePieces;

        void moveSnake(GLfloat newX, GLfloat newY);
        Snake();
};