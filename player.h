#include "olcPixelGameEngine.h"

class player 
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
    // Note:
    //  For our x and y positions, we might wanna use olc::vi2d position; which stores the x,y coordinate as a postion vector {x,y}
    //  but we need to research how to properly use this type "olc::vic2d"
    //  but again, maybe we just wanna use seperate x and y postion vars ... i think we can make it work. 
    float px = 25; 
    float py; // try to get the y position on the line
    float vy;
    float ay;
};
