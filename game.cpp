#include "game.h"
#include "olcPixelGameEngine.h"

bool game::OnUserCreate()
{
	logo.LoadFromFile("test.png");




	return true;
}

bool game::OnUserUpdate(float fElapsedTime)
{
    test();


	return true;
}

void game::test()
{
    DrawSprite(0, 0, &logo);


}