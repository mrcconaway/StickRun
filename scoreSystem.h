#pragma once


#include <chrono>

class scoringSystem{

public:
    scoringSystem()
    {
        score = 0;
	    prevSecond = 0;
    }
    void updateScore(int value = 1);
    int getScore()const;
    void setScore(int value = 0);

    void updatePrevSecond();
    int getPrevSecond()const;
    bool secondElapsed()const;

    int getTime()const;
    void resetTime();

    void startTimer();

private:
    int score;
	int prevSecond;
    std::chrono::high_resolution_clock::time_point timer; 

};

