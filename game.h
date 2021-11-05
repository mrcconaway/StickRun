#pragma once

#include "olcPixelGameEngine.h"
#include "player.h"
#include "enemyBox.h"
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

	void onKeyPress();

	public: 
	player p1;




	public:
	enemyBox eBox;
};