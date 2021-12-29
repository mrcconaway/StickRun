#pragma once


#include <chrono>

class scoringSystem{

public:
    void updateScore(int value = 1);
    int getScore()const;

    int getTime()const;

private:
    int score;
    std::chrono::high_resolution_clock::time_point timer = std::chrono::high_resolution_clock::now(); 

};

