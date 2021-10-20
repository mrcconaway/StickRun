#include "player.h"



float player::getpy(){
    return py;
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



void player::setvy(float x){
    vy = x;
}

void player::setay(float x){
    ay = x;
}