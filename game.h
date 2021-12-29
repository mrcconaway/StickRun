#pragma once

#include "olcPixelGameEngine.h"
#include "player.h"
#include "enemyBox.h"
#include "scoreSystem.h"


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
	void worldDraw();

	void onWPress();
	void onPPress();

	private:
	player p1;
	enemyBox eBox;

	bool hitDetection();
	bool jumpOverDetection(player p, enemyBox e);
	void jumpedEnemyPts(player p, enemyBox e, int pointVal);

	// game State logic
	public: 
	enum StateEngine{
		MENU,
		PAUSE,
		PLAY,
		END
	};

	StateEngine gameState;
	void displayMENU();
	void playGame();
	void gameOver();

	StateEngine getGameState();
	void setStateMenu();
	void setStatePause();
	void setStatePlay();
	void setStateEnd();
	void reset();


	public:
	olc::Sprite Logo;
	olc::Sprite endLogo;


	// scoring system
	scoringSystem score;
	void drawScore();


};