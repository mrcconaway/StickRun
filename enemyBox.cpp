#include "enemyBox.h"

void enemyBox::setModelSize(int size){
        modelSize = size;
} 
void enemyBox::setVelX(float velocity){
        velx = velocity;
        
}
void enemyBox::setVelY(float velocity){
        vely = velocity;
        
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
void enemyBox::setStarYAxis(float start){
        startYAxis = start;
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
void enemyBox::setWeightY(float weight)
{
        weighty = weight;
}

void enemyBox::updateY()
{
        posy += vely;
        if(posy <= startYAxis - 50){
                vely *= -1;
                weighty *= -1;
        }
        else if(posy >= startYAxis + 50){
              vely *= -1;  
              weighty *= -1;
        }
        else{
                return;
        }
}
void enemyBox::updateVelY(){
        vely = vely + weighty;
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

void enemyBox::setPixelColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
        olc::Pixel tmp(red,green,blue, alpha);
        pixelColor = tmp;
}
olc::Pixel enemyBox::getPixelColor()
{
        return pixelColor;
}

