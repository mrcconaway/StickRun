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
    void setStartOfScreen(float start);

    // accessors
    int getModelSize();
    float getVelX();
    float getPosY();
    float getPosX();
    float getStartOfScreen();


    public:
    void update();

private:
    int modelSize; 
    float velx;
    float posy;
    float posx;

    float endOfScreen = 0;
    float startOfScreen;
};