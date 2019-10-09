#include "snakePart.h"
#include <vector>

class Snake 
{
    public:
        int direction;
        int score;
        std::vector<SnakePart*> snakePieces;

        Snake();
        ~Snake();
};