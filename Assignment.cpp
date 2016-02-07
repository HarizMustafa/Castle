/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
 TCS2111 Computer Graphics
Session: Trimester 1, 2015/16
ID and Name #1 : 1112701371 Hariz bin Mohamed Mustafa
Contacts #1 : 013-3642393 HarizzMustafa@gmail.com

********************************************/

#include <GL/glut.h>
#include "CGLabmain.hpp"
#include "Assignment.hpp"

#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace Assignment;

MyCastle::MyCastle()
{
//Setup Quadric Object
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
}

MyCastle::~MyCastle()
{
    gluDeleteQuadric(pObj);
}

void MyCastle::draw()
{
    glDisable(GL_CULL_FACE);
    draw1();
    glColor3f(1.0f, 1.0f, 1.0f);
    //drawCylinderTower();
    //drawCylinderBase();
    //drawTowerBarrier();
    //drawFullTower();
    //drawCastleWalls();
    //draw1x1Fort();
    //draw2x1Fort();
    //draw2x2Fort();
    //draw3x2Fort();
    //drawForts();
    //drawIsland();
    //drawCastleRoof();
    //drawFullCastle();
    //drawHouse();
    //drawTerrain();
    //drawCannon();
    glEnable(GL_CULL_FACE);
}

void MyCastle::draw1()
{
    drawForts();

    glPushMatrix();
    glTranslatef(35.0f, 0.0f, 40.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.5f, 1.0f);
    drawFullCastle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.25f, 0.25f, 0.25f);
    for(float i=0; i<=6; i+=2)
    {
        //right side of barrier
        glPushMatrix();
        glTranslatef(i*10, 0.0f, 10*i); //i is the gap between houses
        glColor3f(1.0f, 0.5, 0.0f);
        drawHouse();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    glRotatef(50.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.25f, 0.25f, 0.25f);
    for(float i=0; i<=6; i+=2)
    {
        //right side of barrier
        glPushMatrix();
        glTranslatef(i*10, 0.0f, 10*i); //i is the gap between houses
        glColor3f(1.0f, 0.5, 0.0f);
        drawHouse();
        glPopMatrix();
    }
    glPopMatrix();

    glColor3f(0.35f, 0.5f, 0.0f);
    drawIsland();

    glPushMatrix();
    glTranslatef(60.0f, -5.0f, -20.0f);
    drawTerrain();
    glPopMatrix();
}

void MyCastle::drawCube()
{
    GLfloat dimx = 2.0, dimy = 1.0, dimz = 2.0;
    GLfloat xmax = dimx/2.0;
    GLfloat xmin = -xmax;
    GLfloat ymax = dimy;
    GLfloat ymin = 0;
    GLfloat zmax = dimz/2.0;
    GLfloat zmin = -zmax;
//Box
    glBegin(GL_QUADS);
//front
    glVertex3f(xmin,ymax,zmax);
    glVertex3f(xmin,ymin,zmax);
    glVertex3f(xmax,ymin,zmax);
    glVertex3f(xmax,ymax,zmax);
//back
    glVertex3f(xmin,ymax,zmin);
    glVertex3f(xmax,ymax,zmin);
    glVertex3f(xmax,ymin,zmin);
    glVertex3f(xmin,ymin,zmin);
//right
    glVertex3f(xmax,ymax,zmax);
    glVertex3f(xmax,ymin,zmax);
    glVertex3f(xmax,ymin,zmin);
    glVertex3f(xmax,ymax,zmin);
//left
    glVertex3f(xmin,ymax,zmax);
    glVertex3f(xmin,ymax,zmin);
    glVertex3f(xmin,ymin,zmin);
    glVertex3f(xmin,ymin,zmax);
//top
    glVertex3f(xmin,ymax,zmax);
    glVertex3f(xmax,ymax,zmax);
    glVertex3f(xmax,ymax,zmin);
    glVertex3f(xmin,ymax,zmin);
//bottom
    glVertex3f(xmin,ymin+0.2,zmax);
    glVertex3f(xmax,ymin+0.2,zmax);
    glVertex3f(xmax,ymin+0.2,zmin);
    glVertex3f(xmin,ymin+0.2,zmin);
    glEnd();
}

void MyCastle::drawCylinderTower()
{
    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluCylinder(pObj, 3.0f, 3.0f, 12.0f, 20, 5);
    glPopMatrix();

}

void MyCastle::drawCylinderBase()
{
    glPushMatrix();
    glTranslatef(0.0f, 12.0f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

    GLfloat x = 0; //x-position of the circle
    GLfloat y = 0; //y-position of the circle
    GLfloat radius = 3; //radius of the circle
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14159;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
    glPopMatrix();
}

void MyCastle::drawTowerBarrier()
{
    glPushMatrix();
    glTranslatef(0.0f, 12.0, 0.0f);

    float rotateRadius = 2.7;//radius for hole
    for(float i=0; i<=360; i+=30) //setting i+=30 produces 12 cubes; the higher the number of i+= the less cubes produced
    {
        glPushMatrix();
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glTranslatef(rotateRadius*i/i, 0.0f, 0.0f); //rotateRadius*i/i so that the cubes will spawn in 360 degrees yet have space between each cube and center of cylinder
        glScalef(0.25, 1.0, 0.5);
        glColor3f(1.0f, 0.5, 0.0f);
        drawCube();
        glPopMatrix();
    }

    glPopMatrix();
}

void MyCastle::drawFullTower()
{
    glPushMatrix();
    drawCylinderTower();
    drawCylinderBase();
    glPushMatrix();
    glTranslatef(0.0f, -12.0f, 0.0f);
    drawCylinderBase();
    glPopMatrix();
    drawTowerBarrier();
    glPopMatrix();
}

void MyCastle::drawCastleWalls()
{
    glPushMatrix();
    glScalef(1.0f, 10.0f, 12.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCube(); //Main wall
    glPopMatrix();

    for(float i=0; i<=23; i+=2)
    {
        //right side of barrier
        glPushMatrix();
        glTranslatef(0.8f, 10.0f, -11.0f); //pushes back the boxes to the end of the wall
        glTranslatef(0.0f, 0.0f, i); //i is the gap between boxes
        glScalef(0.25, 1.0, 0.5);
        glColor3f(1.0f, 0.5, 0.0f);
        drawCube();
        glPopMatrix();

        //left side of barrier
        glPushMatrix();
        glTranslatef(-0.8f, 10.0f, -11.0f); //pushes back the boxes to the end of the wall
        glTranslatef(0.0f, 0.0f, i); //i is the gap between boxes
        glScalef(0.25, 1.0, 0.5);
        glColor3f(1.0f, 0.5, 0.0f);
        drawCube();
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -8.0f);
    glScalef(2.0f, 8.0f, 1.0f);
    glColor3f(0.8f, 0.49f, 0.19f);
    drawCube(); //wall support #1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 8.0f);
    glScalef(2.0f, 8.0f, 1.0f);
    glColor3f(0.8f, 0.49f, 0.19f);
    drawCube(); //wall support #2
    glPopMatrix();
}

void MyCastle::draw1x1Fort() //1 tower 1 wall
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 14.5f);
    drawFullTower();
    glPopMatrix();
    drawCastleWalls();
}

void MyCastle::draw2x1Fort() //2 towers 1 wall
{
    draw1x1Fort();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -14.5f);
    drawFullTower();
    glPopMatrix();
}

void MyCastle::draw2x2Fort() //2 towers 2 walls
{
    draw2x1Fort();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -29.0f);
    drawCastleWalls();
    glPopMatrix();
}

void MyCastle::draw3x2Fort() //3 towers 2 walls
{
    draw2x2Fort();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -43.5f);
    drawFullTower();
    glPopMatrix();
}

void MyCastle::drawForts()
{
    draw3x2Fort();

    glPushMatrix();
    glTranslatef(14.0f, 0.0f, 14.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    draw1x1Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(14.0f, 0.0f, -43.5f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    draw1x1Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(41.5f, 0.0f, -49.5f);
    glRotatef(-245, 0.0, 1.0f, 0.0f);
    draw1x1Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(69.5f, 0.0f, -55.5f);
    glRotatef(90, 0.0, 1.0f, 0.0f);
    draw1x1Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(97.5f, 0.0f, -49.5f);
    glRotatef(60, 0.0, 1.0f, 0.0f);
    draw1x1Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(124.5f, 0.0f, -42.5f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(139.5f, 0.0f, 0.0f);
    draw3x2Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125.5f, 0.0f, 15.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    draw1x1Fort();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(96.5f, 0.0f, 15.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(42.5f, 0.0f, 15.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(55.5f, 0.0f, 26.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(83.5f, 0.0f, 26.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();//Fortress Gate Roof/Body
    glTranslatef(69.5f, 5.0f, 14.0f);
    glScalef(2.37f, 3.0f, 1.2f);
    gluCylinder(pObj, 3.5f, 3.4f, 20.0f, 6, 4);
    glPopMatrix();

    glPushMatrix();//Fortress Gate Roof front cover
    glTranslatef(69.5f, 12.0f, 36.0f);
    glScalef(8.5f, 2.9f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);
    glVertex3f( 1.0f,-1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();//Fortress Gate Roof back cover
    glTranslatef(69.5f, 12.0f, 16.0f);
    glScalef(8.5f, 2.9f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);
    glVertex3f( 1.0f,-1.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(79.5f, 0.0f, 37.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.0f, 0.25f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(59.5f, 0.0f, 37.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.0f, 0.25f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(79.5f, 0.0f, 15.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0, 1.0, 0.25);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(59.5f, 0.0f, 15.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0, 1.0, 0.25);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(59.5f, 9.5f, 26.0f);
    glScalef(3.0, 1.0, 10.0);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(79.5f, 9.5f, 26.0f);
    glScalef(3.0, 1.0, 10.0);
    drawCube();
    glPopMatrix();

    glPushMatrix(); //cannons
    glTranslatef(6.2f, 5.0f, 9.0f);
    glScalef(0.5,0.5,0.5);
    for(float i=0; i<10; i++)
    {
        glTranslatef(4.0, 0.0f, 0.0f);
        drawCannon();
    }
    glPopMatrix();

    glPushMatrix(); //cannons
    glTranslatef(-22.2f, 5.0f, 8.0f);
    glScalef(0.5,0.5,0.5);
    for(float i=0; i<10; i++)
    {
        glTranslatef(4.0, 0.0f, 0.0f);
        drawCannon();
    }
    glPopMatrix();

    glPushMatrix(); //cannons
    glTranslatef(60.2f, 5.0f, 9.0f);
    glScalef(0.5,0.5,0.5);
    for(float i=0; i<10; i++)
    {
        glTranslatef(4.0, 0.0f, 0.0f);
        drawCannon();
    }
    glPopMatrix();

    glPushMatrix(); //cannons
    glTranslatef(87.2f, 5.0f, 9.0f);
    glScalef(0.5,0.5,0.5);
    for(float i=0; i<10; i++)
    {
        glTranslatef(4.0, 0.0f, 0.0f);
        drawCannon();
    }
    glPopMatrix();
}

void MyCastle::drawIsland()
{
    glPushMatrix();
    glTranslatef(70.0f, -8.0f, -12.0f);
    glScalef(75.0f, 8.0f, 50.f);
    drawCube();
    glPopMatrix();
}

void MyCastle::drawCastleRoof()
{
    glColor3f(1.0f, 0.5, 0.0f);
    glBegin(GL_TRIANGLES);
    //pointing upwards
    glNormal3f(0.0f, 1.0f, 0.0f);

    //Note: Anti-clockwise as looking from inside
    //front side
    glVertex3f( 0.0f, 5.0f, 0.0f );
    glVertex3f(-5.0f, -5.0f, 5.0f );
    glVertex3f( 5.0f, -5.0f, 5.0f );

    //right side
    glVertex3f( 0.0f, 5.0f, 0.0f );
    glVertex3f( 5.0f, -5.0f, 5.0f );
    glVertex3f( 5.0f, -5.0f, -5.0f );

    //back side
    glVertex3f( 0.0f, 5.0f, 0.0f );
    glVertex3f( 5.0f, -5.0f, -5.0f );
    glVertex3f(-5.0f, -5.0f, -5.0f );

    //left side
    glVertex3f( 0.0f, 5.0f, 0.0f );
    glVertex3f(-5.0f, -5.0f, -5.0f );
    glVertex3f(-5.0f, -5.0f, 5.0f );

    //bottom side
    glVertex3f(-5.0f,-5.0f,5.0f );
    glVertex3f(-5.0f,-5.0f,-5.0f );
    glVertex3f( 5.0f,-5.0f,5.0f );
    glVertex3f( 5.0f,-5.0f,5.0f );
    glVertex3f(-5.0f,-5.0f,-5.0f );
    glVertex3f( 5.0f,-5.0f,-5.0f );
    glEnd();

}

void MyCastle::drawFullCastle()
{
    glPushMatrix();
    glTranslatef(70.0f, 19.0f, -20.0f);
    glScalef(2.0f, 0.5f, 2.0f);
    drawCastleRoof();
    glPopMatrix();

    glPushMatrix(); //left wall
    glTranslatef(60.0f, 0.0f, -20.0f);
    glScalef(1.0f, 1.7f, 1.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix(); //front left tower
    glTranslatef(60.0f, 0.0f, -10.0f);
    glScalef(1.5f, 1.5f, 1.0f);
    drawFullTower();
    glPopMatrix();

    glPushMatrix(); //Tower Roof Left
    glTranslatef(60.0f, 25.0f, -10.0f);
    glRotatef(90, 1.0, 0.0f, 0.0f);
    gluCylinder(pObj, 0.00625f, 3.0f, 6.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();//right wall
    glTranslatef(80.0f, 0.0f, -20.0f);
    glScalef(1.0f, 1.7f, 1.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix(); //front right tower
    glTranslatef(80.0f, 0.0f, -10.0f);
    glScalef(1.5f, 1.5f, 1.0f);
    drawFullTower();
    glPopMatrix();

    glPushMatrix(); //Tower Roof Right
    glTranslatef(80.0f, 25.0f, -10.0f);
    glRotatef(90, 1.0, 0.0f, 0.0f);
    gluCylinder(pObj, 0.00625f, 3.0f, 6.0f, 24, 72);
    glPopMatrix();

    glPushMatrix(); //front wall
    glTranslatef(70.0f, 0.0f, -10.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.7f, 1.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix(); //back wall
    glTranslatef(70.0f, 0.0f, -30.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.7f, 1.0f);
    drawCastleWalls();
    glPopMatrix();

    glPushMatrix(); //back right tower
    glTranslatef(80.0f, 0.0f, -30.0f);
    glScalef(1.5f, 1.5f, 1.0f);
    drawFullTower();
    glPopMatrix();

    glPushMatrix(); //Tower Roof Back Right
    glTranslatef(80.0f, 25.0f, -30.0f);
    glRotatef(90, 1.0, 0.0f, 0.0f);
    gluCylinder(pObj, 0.00625f, 3.0f, 6.0f, 24, 72);
    glPopMatrix();

    glPushMatrix(); // back left tower
    glTranslatef(60.0f, 0.0f, -30.0f);
    glScalef(1.5f, 1.5f, 1.0f);
    drawFullTower();
    glPopMatrix();

    glPushMatrix(); //Tower Roof Back Left
    glTranslatef(60.0f, 25.0f, -30.0f);
    glRotatef(90, 1.0, 0.0f, 0.0f);
    gluCylinder(pObj, 0.00625f, 3.0f, 6.0f, 24, 72);
    glPopMatrix();
}

void MyCastle::drawHouse()
{
    glPushMatrix();//House Roof/Body
    glTranslatef(69.5f, 5.0f, 14.0f);
    glScalef(2.8f, 3.0f, 1.2f);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 3.5f, 3.4f, 20.0f, 6, 4);
    glPopMatrix();

    glPushMatrix();//House front top cover
    glTranslatef(69.5f, 12.0f, 36.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 3.0f, 0.0f);
    glVertex3f(-8.0f,-2.0f, 0.0f);
    glVertex3f( 8.0f,-2.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();//House back top cover
    glTranslatef(69.5f, 12.0f, 16.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 3.0f, 0.0f);
    glVertex3f(-8.0f,-2.0f, 0.0f);
    glVertex3f( 8.0f,-2.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //House front bottom cover
    glTranslatef(59.5f, -3.0f, 36.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 3.0, 0.0);
    glVertex3f(18.0, 3.0, 0.0);
    glVertex3f(18.0, 13.0, 0.0);
    glVertex3f(2.0, 13.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //House front bottom cover
    glTranslatef(59.5f, -3.0f, 16.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 3.0, 0.0);
    glVertex3f(18.0, 3.0, 0.0);
    glVertex3f(18.0, 13.0, 0.0);
    glVertex3f(2.0, 13.0, 0.0);
    glEnd();
    glPopMatrix();
}

void MyCastle::drawCannon()
{
    glPushMatrix(); //cannon body
    glTranslatef(52.5f, 10.5f, 12.0f);
    glRotatef(-45, 1.0f, 0.0f, 0.0f);
    glColor3f(0.2f,0.2f, 0.2f);
    gluCylinder(pObj, 0.8f, 0.3f, 6.0f, 12, 72);
    glPopMatrix();

    glPushMatrix(); //cannon round back
    glTranslatef(52.5f, 10.5f, 12.0f);
    glRotatef(-45, 1.0f, 0.0f, 0.0f);
    glColor3f(0.2f, 0.2f, 0.2f);
    gluSphere(pObj, 0.8, 12, 12);
    glPopMatrix();

    glPushMatrix(); //right cannon wheels
    glTranslatef(53.5f, 10.5f, 12.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glColor3f(0.9f, 0.9f, 0.9f);
    glutSolidTorus(0.25, 0.5, 12, 12);
    glPopMatrix();

    glPushMatrix(); //left cannon wheels
    glTranslatef(51.5f, 10.5f, 12.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glColor3f(0.9f, 0.9f, 0.9f);
    glutSolidTorus(0.25, 0.5, 12, 12);
    glPopMatrix();
}

///////Random Terrain Generator Variables//////////////////
int width;
int height;
float* vertices = 0;
int* indices = 0;

int getVerticesCount( int width, int height )
{
    return width * height * 3;
}

int getIndicesCount( int width, int height )
{
    return (width*height) + (width-1)*(height-2);
}

float* getVertices( int width, int height )
{
    if ( vertices ) return vertices;

    vertices = new float[ getVerticesCount( width, height ) ];
    int i = 0;

    for ( int row=0; row<height; row++ )
    {
        for ( int col=0; col<width; col++ )
        {
            vertices[i++] = (float) col;
            vertices[i++] = 0.0f;
            vertices[i++] = (float) row;
        }
    }

    return vertices;
}

void MyCastle::drawTerrain()
{
    glDisable(GL_CULL_FACE);

    glPushMatrix();
    glScalef(5,.5,5);
    glTranslatef(-15,0,-15);
    int MAP_SIZE = 35;

    time_t seconds; //variable that holds seconds on clock
    time(&seconds); //Get value from system clock and place in seconds variable.
    srand((unsigned int)seconds); //converts seconds to unsigned integer

    int height[100][100];

    for (int i = 0; i < MAP_SIZE ; i++)
    {
        for (int j = 0; j < i ; j++)
        {
            height[j][i]=rand()%8; //lower left side randomized terrain height
            height[i][j]=rand()%4; //upper right side randomized terrain height
        }
    }

    for (int x = 1; x < MAP_SIZE-1; x++)
    {
        for (int z = 1; z < MAP_SIZE-1; z++)
        {
            glColor3f(0.0f, 0.5f, 1.0f );
            glBegin(GL_QUADS);
            glNormal3f(0.0f, 1.0f, 0.0f);
            glVertex3f(   x, height[x][z]    , z );
            glVertex3f( x+1, height[x+1][z]  , z );
            glVertex3f( x+1, height[x+1][z+1], z + 1);
            glVertex3f(   x, height[x][z+1]  , z + 1);
            glEnd();
        }
    }

    glPopMatrix();
}

MovingGate::MovingGate()
{
    timetick = 0;
    vel0 = 10.0;
    accel = -0.005;
}

void MovingGate::drawGate()
{
    float y = vel0*1 + 0.5*accel*0.5*timetick;
    if (y < 0.0)
    {
        y = 0.0;
        timetick = 0;
    }
    glColor3f(0.5f, 0.5f, 0.5f );
    glTranslatef(70.0f, -4.0f, 34.0f);
    glTranslatef(0.0f, y, 0.0f);
    glScalef(4.0f, 2.0f, 0.25f);
    glutSolidCube(4);
    glutPostRedisplay();
}

void MovingGate::tickTime(long int elapseTime)
{
    timetick += elapseTime;
}
