#include "olcPixelGameEngine.h"
#include "game.h"

int main()
{
    game test;
    test.Construct(256, 240, 4, 4);
    test.Start();

    return 0;
}