#include "draw.h"

Draw::Draw() {
    srand(time(NULL));
    xSize = startingSize;
    ySize = startingSize;
}

void Draw::increaseSnakeSize() 
{
    xSize += startingSize;
}

void Draw::quadDraw(GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B) 
{
    //float colorRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    
    glPushMatrix();
	glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        glColor3f(R,G,B);                      // Draw A Quad
        glVertex3f( -xSize, ySize, 0.0f);              // Top Left
        glVertex3f( xSize, ySize, 0.0f);              // Top Right
        glVertex3f( xSize,-ySize, 0.0f);              // Bottom Right
        glVertex3f(-xSize,-ySize, 0.0f);              // Bottom Left
    glEnd();
    glFlush();				/* Complete any pending operations */
    glPopMatrix();
}   

float Draw::randQuadSize() {
    //float sizeRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float sizeRand = 0.02f;
    return sizeRand;
}

void Draw::quadDrawWithSize(GLfloat x, GLfloat y, GLfloat sizeX, GLfloat sizeY, GLfloat R, GLfloat G, GLfloat B) 
{
    glPushMatrix();
	glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        glColor3f(R,G,B);                      // Draw A Quad
        glVertex3f( -sizeX, sizeY, 0.0f);              // Top Left
        glVertex3f( sizeX, sizeY, 0.0f);              // Top Right
        glVertex3f( sizeX,-sizeY, 0.0f);              // Bottom Right
        glVertex3f(-sizeX,-sizeY, 0.0f);              // Bottom Left
    glEnd();
    glFlush();				/* Complete any pending operations */
    glPopMatrix();
}

void Draw::glfwKeyCallback() 
{

}

void Draw::DrawSquare(GLfloat x, GLfloat y)
{
	
}
