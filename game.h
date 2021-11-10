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
		gameState = MENU;
	}
	bool OnUserCreate()override;
	bool OnUserUpdate(float fElapsedTime) override;
	void gameDraw();

	void onKeyPress();

	private:
	player p1;
	enemyBox eBox;


	// game State logic
	public: 
	enum StateEngine{
		MENU,
		PAUSE,
		START
	};

	StateEngine gameState;
	void displayMENU();



};