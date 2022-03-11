#pragma once

class enemyBox
{
public:
    enemyBox(){
        modelSize = 0;
        velx = 0.0f;
        posy = 0.0f;
        posx = 0.0f;
        startOfScreen = 0.0f;
        isDrawn = false;
    }

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

private:
    bool isDrawn;
};