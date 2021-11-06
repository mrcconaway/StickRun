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
