#pragma once


class player 
{

public:
    player(float x = 0, float y = 0){
        py = y;
        floor = py;
    } // constructor 

    //accessor functions
    float getpy();
    float getpx();
    float getvy();
    float getay();
    //mutator functions
    void setpy(float x);
    void setfloor(float x);
    void setvy(float x);
    void setay(float x);

    //mutators
    void updatepy();
    void updatevy();

private:
    float px = 50; 
    float py = 0; // try to get the y position on the line
    float vy = 0;
    float ay = 0.1;
    // where is the ground?
    float floor;
};
