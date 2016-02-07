/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
 TCS2111 Computer Graphics
Session: Trimester 1, 2015/16
ID and Name #1 : 1112701371 Hariz bin Mohamed Mustafa
Contacts #1 : 013-3642393 HarizzMustafa@gmail.com

********************************************/

#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include "CGLabmain.hpp"

namespace Assignment
{

class MyCastle
{
public:
    MyCastle();
    ~MyCastle();
    void draw();
    void draw1();
//functions to draw castle pieces
    void drawCylinderTower();
    void drawCylinderBase();
    void drawTowerBarrier();
    void drawFullTower();
    void drawCastleWalls();
    void draw1x1Fort();
    void draw2x1Fort();
    void draw2x2Fort();
    void draw3x2Fort();
    void drawForts();
    void drawIsland();
    void drawCastleRoof();
    void drawFullCastle();
    void drawHouse();
    void drawTerrain();
    void drawCannon();
private:
    void drawCube();
    GLUquadricObj *pObj;
};

class MovingGate
{
 public:
    MovingGate();
    void drawGate();
    void tickTime(long int elapseTime);
 private:
    long int timetick;
    float vel0;
    float accel;
};

class MyVirtualWorld
{
public:
    MyCastle mycastle;
    MovingGate movinggate;

    long int timeold, timenew, elapseTime;

    void draw()
    {
        mycastle.draw();
        movinggate.drawGate();
    }

    void tickTime()
    {
     timenew    = glutGet(GLUT_ELAPSED_TIME);
     elapseTime = timenew - timeold;
     timeold    = timenew;

     movinggate.tickTime(elapseTime);
    }

    void init()
    {
    }
};
};
#endif
