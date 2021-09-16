#include "player.h"


float player::getCoordinateY(){
    return py;
}
float player::getCoordinateX(){
    return px;
}
float player::playerVelocity(){
    return vy;
}
float player::playerAcceloration(){
    return ay;
}
void player::setPlayerY(float x){
    py = x;
}
void player::setVelocity(float x){
    vy = x;
}void player::setAcceloration(float x){
    ay = x;
}