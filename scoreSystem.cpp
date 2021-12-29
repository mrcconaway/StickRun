#include "scoreSystem.h"
#include <iostream>

void scoringSystem::updateScore(int value)
{
    score += value;
}

int scoringSystem::getScore()const
{
    return score;
}

void scoringSystem::setScore(int value)
{
    score = value;
}

int  scoringSystem::getTime()const
{
    std::chrono::high_resolution_clock::time_point tmp = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(tmp - timer).count();
}

void scoringSystem::updatePrevSecond()
{
    prevSecond = getTime();
}

int scoringSystem::getPrevSecond()const
{
    return prevSecond;
}

bool scoringSystem::secondElapsed()const
{
    return ( getTime() > prevSecond );
}

void scoringSystem::resetTime()
{
    timer = std::chrono::high_resolution_clock::now();
    prevSecond = 0;
}

void scoringSystem::startTimer()
{
    timer = std::chrono::high_resolution_clock::now();
}
void scoringSystem::startPointTimer()
{
    pointTimer = std::chrono::high_resolution_clock::now();
}

int scoringSystem::pointTimerSecondElapsed()
{
    std::chrono::high_resolution_clock::time_point tmp = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(tmp - pointTimer).count();
}
