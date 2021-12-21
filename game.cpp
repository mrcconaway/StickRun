// TODO: Look into how the pixelgameEngine renders text

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
    float x_pos = ScreenWidth() * 0.75;
    p1.setpy( y_pos );
    p1.setfloor( y_pos );
    p1.setModelSize(10);


    eBox.setModelSize(5);
    eBox.setVelX(-0.8);
    eBox.setPosY(y_pos);
    eBox.setPosX(x_pos);
    eBox.setStartOfScreen(ScreenWidth());

    Logo.LoadFromFile("NotARipOffLogo.png");
    



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

                // Draw enemy
                if( (eBox.getPosX() < x + eBox.getModelSize() ) && (eBox.getPosX() > x - eBox.getModelSize() ) ){
                    if( ( eBox.getPosY() < y + eBox.getModelSize() ) && (eBox.getPosY() > y - eBox.getModelSize() ) ){
                        PixelGameEngine::Draw(x, y, olc::Pixel(255,  0,  0));
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

}



// figure out inputs and then update player class vy
void game::onKeyPress(){
    std::cout << "W is Pressed:" << std::endl;
    if(p1.getpy() == p1.getfloor())
        p1.setvy(-4.00);
}






// game state logic

void game::displayMENU()
{
    worldDraw();

 

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
    PixelGameEngine::DrawSprite(500, 250, &Logo, 800);


}


void game::playGame()
{

    // update playter position
    if(GetKey(olc::W).bPressed){
    	onKeyPress();
    }

    p1.updatepy();


    // update enemy box positon
    eBox.update();


    gameDraw();

}