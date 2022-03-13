#pragma once

#include "olcPixelGameEngine.h"
#include "player.h"
#include "enemyBox.h"
#include "scoreSystem.h"
#include <vector>


class game : public olc::PixelGameEngine
{
public:
	game()
	{
		sAppName = "Stick Run";
		// gameState = MENU;
		gameState = PLAY;
	}
	bool OnUserCreate()override;
	bool OnUserUpdate(float fElapsedTime) override;
	void gameDraw();
	void worldDraw();
	void startGame();

	void onWPress();

	private:
	player p1;
	std::vector<enemyBox> eBox;

	public:
	bool hitDetection( enemyBox e);
	bool jumpOverDetection(player p, enemyBox e);
	void jumpedEnemyPts(player p, enemyBox e, int pointVal);

	private:
	bool addJumpPts = false;

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