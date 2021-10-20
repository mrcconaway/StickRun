#pragma once

#include "olcPixelGameEngine.h"
#include "player.h"
class game : public olc::PixelGameEngine
{
public:
	game()
	{
		sAppName = "Stick Run";
	}
	bool OnUserCreate()override;
	bool OnUserUpdate(float fElapsedTime) override;
	void gameDraw();

	public: 
	player p1;
};