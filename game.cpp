#include "game.h"
#include "player.h"
#include "olcPixelGameEngine.h"
#include <iostream>

// initize game stuff
bool game::OnUserCreate()
{
    float y_pos = ScreenHeight() * 0.75;
    p1.setpy( y_pos);
    p1.setfloor(y_pos);
    return true;
}

// update game stuff
bool game::OnUserUpdate(float fElapsedTime) 
{
    if(GetKey(olc::W).bHeld){
    	onKeyPress();
    }
    p1.updatepy();
    gameDraw();

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

                // Draw Player
                if( (p1.getpx() < x + 10 ) && (p1.getpx() > x - 10 ) ){
                    if( (p1.getpy() < y + 10 ) && (p1.getpy() > y - 10 )){
                        PixelGameEngine::Draw(x, y, olc::Pixel(0,  0,  0));
                    }
                }



            } // end for y loop
        } // end for x loop

}



// figure out inputs and then update player class vy
void game::onKeyPress(){
    p1.setvy(20);
}
