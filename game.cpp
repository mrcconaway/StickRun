#include "game.h"
#include "olcPixelGameEngine.h"

game::game()
{
    sAppName = "Stick Run";
}

bool game::OnUserCreate()
{
    return true;
}

bool game::OnUserUpdate(float fElapsedTime) 
{
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






            } // end for y loop
        } // end for x loop

}
