#pragma once


class player 
{

public:
    player(int size = 0, float x = 0, float y = 0){
        setModelSize(size);
        setpy(y);
        setfloor(y);
    } // constructor 

    //accessor functions
    float getpy();
    float getpx();
    float getvy();
    float getay();
    float getfloor();
    int getModelSize();


    //mutator functions
    void setpy(float x);
    void setfloor(float x);
    void setvy(float x);
    void setay(float x);
    void setModelSize(int size);


    //mutators
    void updatepy();
    void updatevy();

private:
    float px = 50; 
    float py = 0; // try to get the y position on the line
    float vy = 0;
    float ay = 20;
    // where is the ground?
    float floor;

    int modelSize;
};
