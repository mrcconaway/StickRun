#include "olcPixelGameEngine.h"

class player : public olc::PixelGameEngine
{

public:
    player(){} // constructor 

    //accessor functions
    float getCoordinateY();
    float getCoordinateX();
    float playerVelocity();
    float playerAcceloration();
    //mutator functions
    void setPlayerY(float x);
    void setVelocity(float x);
    void setAcceloration(float x);
private:
    float px = 25; 
    float py = ScreenHeight() * 0.75 + 1; // try to get the y position on the line
    float vy;
    float ay;
};
