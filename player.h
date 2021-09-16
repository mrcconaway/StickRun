#include "olcPixelGameEngine.h"

class player : public olc::PixelGameEngine
{

public:
    //accessor functions
    float getCoordinateY();
    float getCoordinateX();

private:
    float px = 25; 
    float py = ScreenHeight() * 0.75 + 1; // try to get the y position on the line
};
