#pragma once


#include <chrono>

class scoringSystem{

public:
    scoringSystem()
    {
        score = 0;
        timer = std::chrono::high_resolution_clock::now();
    }
    void updateScore(int value = 1);
    int getScore()const;
    void setScore(int value = 0);

    int getTime()const;
    void resetTime();

private:
    int score;
    std::chrono::high_resolution_clock::time_point timer = std::chrono::high_resolution_clock::now(); 

};

