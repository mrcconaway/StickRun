#pragma once
#include "olcPixelGameEngine.h"
#include <chrono>


// TODO look into including pixelGameEngine's olc::Pixel
// so I can make each enemy a different color
class enemyBox
{
public:
    enemyBox(){
        modelSize = 0;
        velx = 0.0f;
        vely = 0.0f;
        posy = 0.0f;
        posx = 0.0f;
        weighty = 0.0f;
        startOfScreen = 0.0f;
        startYAxis = 0.0f;
        
        isDrawn = false;
        pointValue = 0;
        jumped = false;

        pixelColor = olc::Pixel();
    }

    // mutators
    void setModelSize(int size);
    void setVelX(float velocity);
    void setVelY(float velocity);
    void updateVelY();
    void setWeightY(float weight);
    void setPosY(float positionY);
    void setPosX(float positionX);
    void setStartOfScreen(float start);
    void setStarYAxis(float start);
    void setPointValue(int val);
    void setIsDraw(bool in);
    void setJumped(bool in);
    

    // accessors
    int getModelSize();
    float getVelX();
    float getPosY();
    float getPosX();
    float getStartOfScreen();
    int getPointValue();
    bool getIsDrawn();
    bool getJumped();

public:
    void startJumpedTimer();
    int jumpedTimerSecondElapsed();
public:
    void setPixelColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    olc::Pixel getPixelColor();

public:
    void update();
    void updateY();


private:
    int modelSize; 
    float velx;
    float vely;
    float posy;
    float posx;
    float weighty;

    float endOfScreen = 0;
    float startOfScreen;
    float startYAxis;

private:
    bool isDrawn;
    int pointValue;
    bool jumped;

private:
    std::chrono::high_resolution_clock::time_point jumpedTimer;

private:
    olc::Pixel pixelColor; 
};