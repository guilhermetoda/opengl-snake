#include "mathCompare.h"



bool MathLib::Compare(GLfloat x, GLfloat y) 
{
	float absDifference = (float) fabs(x - y);

	if (absDifference < 0.04f)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
