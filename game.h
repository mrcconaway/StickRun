#pragma once

#include "olcPixelGameEngine.h"
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
	olc::Sprite logo;
};

