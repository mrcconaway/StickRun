#pragma once


// TODO look into including pixelGameEngine's olc::Pixel
// so I can make each enemy a different color
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
        pointValue = 0;
    }

    // mutators
    void setModelSize(int size);
    void setVelX(float velocity);
    void setPosY(float positionY);
    void setPosX(float positionX);
    void setStartOfScreen(float start);
    void setPointValue(int val);
    void setIsDraw(bool in);
    

    // accessors
    int getModelSize();
    float getVelX();
    float getPosY();
    float getPosX();
    float getStartOfScreen();
    int getPointValue();
    bool getIsDrawn();


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
    int pointValue;
};