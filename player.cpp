#include "player.h"


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
int player::getModelSize()
{
    return modelSize;
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

void player::setModelSize(int size)
{
    modelSize = size;
}


void player::updatepy()
{

    if( (py <= floor) ){
        py = py + vy;
        updatevy();
    }
    else{ // safety net
        setJumpingFalse();
        setDoubleJumpingFalse();
        py = floor;
        vy = 0.0;
    }

}

void player::updatevy()
{
    if( vy != 0.0)
        vy = vy + 0.1;
}

bool player::isJumping()
{
    return jump;
}
bool player::isDoubleJumping()
{
    return doubleJump;
}
void player::setJumpingTrue()
{
    jump = true;
}
void player::setJumpingFalse()
{
    jump = false;
}
void player::setDoubleJumpingTrue()
{
    doubleJump = true;
}
void player::setDoubleJumpingFalse()
{
    doubleJump = false;
}
