#include "enemyBox.h"

void enemyBox::setModelSize(int size){
        modelSize = size;
} 
void enemyBox::setVelX(float velocity){
        velx = velocity;
        
}
void enemyBox::setPosY(float positionY){
        posy = positionY;
}
void enemyBox::setPosX(float positionX){
        posx = positionX;
}

void enemyBox::setStartOfScreen(float start){
        startOfScreen = start;
}


int enemyBox::getModelSize(){
        return modelSize;
}
float enemyBox::getVelX(){
        return velx;
}


float enemyBox::getPosY()
{
        return posy;
}
float enemyBox::getPosX()
{
        return posx;
}
float enemyBox::getStartOfScreen(){
        return startOfScreen;
}


void enemyBox::update()
{
        if(posx > endOfScreen)
                posx = posx + velx;
        else 
                posx = startOfScreen;
}


void enemyBox::setPointValue(int val)
{
        pointValue = val;
}

int enemyBox::getPointValue()
{
        return pointValue;
}

void enemyBox::setIsDraw(bool in)
{
        isDrawn = in;
}
bool enemyBox::getIsDrawn()
{
        return isDrawn;
}

void enemyBox::setJumped(bool in)
{
        jumped = in;
}
bool enemyBox::getJumped()
{
        return jumped;
}
void enemyBox::startJumpedTimer()
{
    jumpedTimer = std::chrono::high_resolution_clock::now();
}

int enemyBox::jumpedTimerSecondElapsed()
{
    std::chrono::high_resolution_clock::time_point tmp = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(tmp - jumpedTimer).count();
}