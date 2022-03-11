// TODO: Look into how the pixelgameEngine renders text
//	Make a better sprite

// TODO: Add a PAUSE game State

// TODO: Add a way to switch between game states


#include "game.h"
#include "player.h"
#include "olcPixelGameEngine.h"
#include <iostream>

// initize game stuff
bool game::OnUserCreate()
{
    float y_pos = ScreenHeight() * 0.75;
    float x_pos = ScreenWidth();
    p1.setpy( y_pos );
    p1.setfloor( y_pos );
    p1.setModelSize(10);

    eBox.push_back(enemyBox());

    eBox[0].setModelSize(5);
    eBox[0].setVelX(-0.8);
    eBox[0].setPosY(y_pos);
    eBox[0].setPosX(x_pos);
    eBox[0].setStartOfScreen(ScreenWidth());
    eBox[0].setPointValue(2);

    Logo.LoadFromFile("NotARipfOffLogo.png");
    endLogo.LoadFromFile("loser.png");
    // Logo.LoadFromFile("notaripoff.png");
    // Logo.LoadFromFile("test.png");
    



    return true;
}

// update game stuff
bool game::OnUserUpdate(float fElapsedTime) 
{

    switch(gameState){
        default:
            break;
        case MENU:
            displayMENU();
            break;
        case PAUSE:
            break;
        case PLAY:
            playGame();
            break;
        case END:
            //still needs implemented
            gameOver();
            break;
    }



    return true;
}

void game::gameDraw()
{
	// called once per frame
	for (int x = 0; x < ScreenWidth(); x++){
		for (int y = 0; y < ScreenHeight(); y++){





            if( (y == int(ScreenHeight() * 0.75 ) ) ){ // draw a black line for a road
                PixelGameEngine::Draw(x, y, olc::Pixel(0,  0,  0));
            }
            else if(y > int(ScreenHeight() * 0.75 ) ) // draw some grass below the black line
            {
                PixelGameEngine::Draw(x, y, olc::Pixel(50,  255,  50));
            }
            else{
                PixelGameEngine::Draw(x, y, olc::Pixel(255,  255,  255));
           }
            for(int i = 0; i < eBox.size(); i++){
                // Draw enemy
                if( (eBox[i].getPosX() < x + eBox[i].getModelSize() ) && (eBox[i].getPosX() > x - eBox[i].getModelSize() ) ){
                    if( ( eBox[i].getPosY() < y + eBox[i].getModelSize() ) && (eBox[i].getPosY() > y - eBox[i].getModelSize() ) ){
                        PixelGameEngine::Draw(x, y, olc::Pixel(255,  0,  0));
                    }
                }   
            }
         
            // Draw Player
            if( (p1.getpx() < x + p1.getModelSize() ) && (p1.getpx() > x - p1.getModelSize() ) ){
                if( (p1.getpy() < y + p1.getModelSize() ) && (p1.getpy() > y - p1.getModelSize() )){
                    PixelGameEngine::Draw(x, y, olc::Pixel(0,  0,  0));
                }
            }

        } // end for y loop
    } // end for x loop
    drawScore();
    if(addJumpPts){
        if(score.pointTimerSecondElapsed() < 1){
            DrawString(p1.getpx() + 2, p1.getpy() - 25, "+" + std::to_string(2), olc::DARK_YELLOW );
        }
        else{
            addJumpPts = false;
        }
    }
}



// figure out inputs and then update player class vy
void game::onWPress(){
    // std::cout << "W is Pressed:" << std::endl;
    if(p1.getpy() == p1.getfloor())
        p1.setvy(-4.00);
}






// game state logic

void game::displayMENU()
{
    worldDraw();
    PixelGameEngine::DrawSprite(0, 0, &Logo, 0.5);
	if(GetKey(olc::P).bPressed){
        startGame();
    }


 

}

void game::startGame()
{
    score.startTimer();
    setStatePlay();
}


void game::worldDraw()
{


	// called once per frame
	for (int x = 0; x < ScreenWidth(); x++){
		for (int y = 0; y < ScreenHeight(); y++){
               if( (y == int(ScreenHeight() * 0.75 ) ) ){ // draw a black line for a road
                   PixelGameEngine::Draw(x, y, olc::Pixel(0,  0,  0));
               }
               else if(y > int(ScreenHeight() * 0.75 ) ) // draw some grass below the black line
               {
                   PixelGameEngine::Draw(x, y, olc::Pixel(50,  255,  50));
               }
               else{
                   PixelGameEngine::Draw(x, y, olc::Pixel(255,  255,  255));
              }
               // TODO: LOOK HOW PIXELGAMEENGINE HANDLES RENDERING TEXT //
           } // end for y loop
       } // end for x loop


}

void game::gameOver()
{
    worldDraw();
    PixelGameEngine::DrawSprite(0, 0, &endLogo, 0.5);
    if(GetKey(olc::R).bPressed){
        reset();
    }
    DrawString(int(ScreenWidth()*0.4), 75, "Final Score: " + std::to_string(score.getScore()), olc::RED );
}

void game::playGame()
{

    // update playter position
    if(GetKey(olc::W).bPressed){
    	onWPress();
    }

    p1.updatepy();
    // update enemy box positon
    for(int i = 0; i < eBox.size(); ++i){

        eBox[i].update();
        if(   hitDetection(eBox[i]) ){ 
            setStateEnd(); // game over
        }
        else if( jumpOverDetection(p1,eBox[i]) ){
            jumpedEnemyPts(p1, eBox[i], eBox[i].getPointValue());
            addJumpPts = true;
            score.startPointTimer();
        }
    }

    gameDraw();

    if(score.getScore() == 25){ // first threshhold for new enemy so it goes to index 1
        eBox.push_back(enemyBox());
            float y_pos = ScreenHeight() * 0.75;
            float x_pos = ScreenWidth();
            eBox[1].setModelSize(3);
            eBox[1].setVelX(-2);
            eBox[1].setPosY(y_pos);
            eBox[1].setPosX(x_pos);
            eBox[1].setStartOfScreen(ScreenWidth());
            eBox[1].setPointValue(5);
    }


}

bool game::hitDetection( enemyBox e )
{
        return( int(e.getPosX() - e.getModelSize()) < p1.getpx() + p1.getModelSize() ) // did they collide on the x-axis?
        && ( int(e.getPosX() + e.getModelSize()) > p1.getpx() - p1.getModelSize() ) 
        &&  ( int( p1.getpy() +  p1.getModelSize() +  e.getModelSize() ) >  e.getPosY() + e.getModelSize() ); // did they collide on the y-axis too?
}

bool game::jumpOverDetection(player p, enemyBox e)
{
    return ( int( p.getpx() - p.getModelSize() ) == int( e.getPosX() + e.getModelSize() ) );

}


/**
 * @brief If the player successfully jumps over the enemyBox, then they get awarded a point
 * 
 * @param p -- player 
 * @param e -- enemy box
 * @param pointVal -- point val
 * 
 * @details Checks to see if the player jumped over enemy box and rewards the player with an extra point (provided by the int pointVal)
 * @details I want to add new enemies and have them be worth varying points based off of their difficulty. For future features, perhaps each enemyBox will have a "point" value making the pointVal parameter redundent
 */
void game::jumpedEnemyPts(player p, enemyBox e, int pointVal)
{
    score.updateScore(pointVal);
}



game::StateEngine game::getGameState()
{
    return gameState;
}
void game::game::setStateMenu()
{
    gameState = MENU;
}
void game::game::setStatePause()
{
    gameState = PAUSE;
}
void game::game::setStatePlay()
{
    gameState = PLAY;
}
void game::setStateEnd()
{
    gameState = END;
}

void game::reset()
{
    float y_pos = ScreenHeight() * 0.75;
    float x_pos = ScreenWidth() * 0.75;
    p1.setpy( y_pos );
    p1.setvy(0.0);

    eBox[0].setModelSize(5);
    eBox[0].setVelX(-0.8);
    eBox[0].setPosX(x_pos);
    eBox[0].setStartOfScreen(ScreenWidth());
    eBox.pop_back();

    score.setScore(0);
    score.resetTime();

    setStatePlay();
}


void game::drawScore()
{
    int32_t x_pos = ScreenWidth()-ScreenWidth()*0.40;
    // std::cout << score.getScore() << std::endl;
    std::string scoreString = std::to_string(score.getScore());
    while( scoreString.size() < 5 ){
        // std::cout << scoreString.size() << std::endl;
        scoreString = "0"+scoreString;
    } 

    DrawString(x_pos,4, "Score: " + scoreString, olc::BLACK);
    if(score.secondElapsed()){
        score.updateScore(score.getTime() - score.getPrevSecond() );
        score.updatePrevSecond();
    }
}