#pragma once

#include "olcPixelGameEngine.h"
#include "player.h"
#include "enemyBox.h"
#include "scoreSystem.h"
#include <vector>
#include <fstream>
#include <filesystem>


class game : public olc::PixelGameEngine
{
public:
	game()
	{
		sAppName = "Stick Run";
		gameState = MENU;
		openfile();
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
	void jumpedEnemyPts( int pointVal);

	private:
	bool addJumpPts = false;

	// game State logic
	public: 
	enum StateEngine{
		MENU,
		PAUSE,
		PLAY,
		END,
		QUIT
	};

	StateEngine gameState;
	void displayMENU();
	void playGame();
	void gameOver();
	void quit();

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


	// high score
	std::string highscorePath = "resource/highscore.dat";
	std::ifstream finp; 
	std::ofstream fout;
	void openfile();
	void create_dir();
    void readFile(std::ifstream& inp);
	void saveFile();
	void save(std::ostream& out);
	std::vector<int> highscore;
	int calls = 0;

};