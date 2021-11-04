#include "player.h"
#include <iostream>


float player::getpy(){
    return py;
}
float player::getfloor(){
    return floor;
}
float player::getpx(){
    return px;
}
float player::getvy(){
    return vy;
}
float player::getay(){
    return ay;
}


void player::setpy(float x){
    py = x;
}

void player::setfloor(float x)
{
    floor = x;
}


void player::setvy(float x){
    vy = x;
}

void player::setay(float x){
    ay = x;
}

void player::updatepy()
{

    if( (py <= floor) ){
        py = py + vy;
        updatevy();
    }
    else{ // safety net
        py = floor;
        vy = 0;
    }

}

void player::updatevy()
{
    vy = vy + 0.1;
}