#pragma once

class enemyBox
{
public:
    enemyBox(){}

    // mutators
    void setModelSize(int size);
    void setVelX(float velocity);
    void setPosY(float positionY);
    void setPosX(float positionX);

    // accessors
    int getModelSize();
    float getVelX();
    float getPosY();
    float getPosX();

private:
    int modelSize; 
    float velx;
    float posy;
    float posx;
};