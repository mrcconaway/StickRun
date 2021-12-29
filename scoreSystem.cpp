#include "scoreSystem.h"

void scoringSystem::updateScore(int value)
{
    score += value;
}

int scoringSystem::getScore()const
{
    return score;
}

int  scoringSystem::getTime()const
{
    std::chrono::high_resolution_clock::time_point tmp = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(tmp - timer).count();
}