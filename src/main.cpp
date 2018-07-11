#include <iostream>
#include <display.hpp>


#ifndef SDL_INCLUDES                                                       
#define SDL_INCLUDES                                                       
#include <SDL2/SDL_image.h>                                                
#include <SDL2/SDL.h>                                                      
#endif 

using namespace std;

bool quit = false, muted = true, start = false;

int main( int argc, char* args[] )
{   
    int xMouse, yMouse;
    bool quit = false, muted = true, start = false;
    Display display;
    SDL_Event e; //Event handler
    char initial_game_code_table[8][8] =
        {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 0, 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { 'P'}, //These will be filled with 0
        { },
        { },
        { },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
        };

    display.displayBoard(initial_game_code_table);    
    while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
					case SDLK_SPACE:
						if (start) {
							display.displayBoard(initial_game_code_table);
                        }
						else start = true;
                    case SDL_MOUSEBUTTONDOWN:
                        display.setDragging(true);
					break;

				}
            
			}
            else if(e.type == SDL_MOUSEBUTTONDOWN ){
                display.setDragging(true);
                SDL_GetMouseState(&xMouse,&yMouse);
                if(xMouse-50 >= 0 && xMouse-50 < 75){
                    display.pieceCoordinatex = 0;
                }
                else if (xMouse-50 >= 75 && xMouse-50 < 150){
                    display.pieceCoordinatex = 1;
                }
                else if (xMouse-50 >= 150 && xMouse-50 < 225){
                    display.pieceCoordinatex = 2;
                }
                else if (xMouse-50 >= 225 && xMouse-50 < 300){
                    display.pieceCoordinatex = 3;
                }
                else if (xMouse-50 >= 300 && xMouse-50 < 375){
                    display.pieceCoordinatex = 4;
                }
                else if (xMouse-50 >= 375 && xMouse-50 < 450){
                    display.pieceCoordinatex = 5;
                }
                else if (xMouse-50 >= 450 && xMouse-50 < 525){
                    display.pieceCoordinatex = 6;
                }
                else{
                    display.pieceCoordinatex = 7;
                }
                if(yMouse-25 >= 0 && yMouse-25 < 75){
                    display.pieceCoordinatey = 0;
                }
                else if (yMouse-25 >= 75 && yMouse-25 < 150){
                    display.pieceCoordinatey = 1;
                }
                else if (yMouse-25 >= 150 && yMouse-25 < 225){
                    display.pieceCoordinatey = 2;
                }
                else if (yMouse-25 >= 225 && yMouse-25 < 300){
                    display.pieceCoordinatey = 3;
                }
                else if (yMouse-25 >= 300 && yMouse-25 < 375){
                    display.pieceCoordinatey = 4;
                }
                else if (yMouse-25 >= 375 && yMouse-25 < 450){
                    display.pieceCoordinatey = 5;
                }
                else if (yMouse-25 >= 450 && yMouse-25 < 525){
                    display.pieceCoordinatey = 6;
                }
                else{
                    display.pieceCoordinatey = 7;

                }
                //Call engine to Validate
                display.pieceType = initial_game_code_table[display.pieceCoordinatex][display.pieceCoordinatey];
            }
            
            else if(e.type == SDL_MOUSEBUTTONUP ){
                initial_game_code_table[display.pieceCoordinatex][display.pieceCoordinatey] = 0;
                display.setDragging(false);
                SDL_GetMouseState(&xMouse,&yMouse);
                if(xMouse-50 >= 0 && xMouse-50 < 75){
                    display.MouseCoordinatex = 0;
                }
                else if (xMouse-50 >= 75 && xMouse-50 < 150){
                    display.MouseCoordinatex = 1;
                }
                else if (xMouse-50 >= 150 && xMouse-50 < 225){
                    display.MouseCoordinatex = 2;
                }
                else if (xMouse-50 >= 225 && xMouse-50 < 300){
                    display.MouseCoordinatex = 3;
                }
                else if (xMouse-50 >= 300 && xMouse-50 < 375){
                    display.MouseCoordinatex = 4;
                }
                else if (xMouse-50 >= 375 && xMouse-50 < 450){
                    display.MouseCoordinatex = 5;
                }
                else if (xMouse-50 >= 450 && xMouse-50 < 525){
                    display.MouseCoordinatex = 6;
                }
                else{
                    display.MouseCoordinatex = 7;
                }
                if(yMouse-25 >= 0 && yMouse-25 < 75){
                    display.MouseCoordinatey = 0;
                }
                else if (yMouse-25 >= 75 && yMouse-25 < 150){
                    display.MouseCoordinatey = 1;
                }
                else if (yMouse-25 >= 150 && yMouse-25 < 225){
                    display.MouseCoordinatey = 2;
                }
                else if (yMouse-25 >= 225 && yMouse-25 < 300){
                    display.MouseCoordinatey = 3;
                }
                else if (yMouse-25 >= 300 && yMouse-25 < 375){
                    display.MouseCoordinatey = 4;
                }
                else if (yMouse-25 >= 375 && yMouse-25 < 450){
                    display.MouseCoordinatey = 5;
                }
                else if (yMouse-25 >= 450 && yMouse-25 < 525){
                    display.MouseCoordinatey = 6;
                }
                else{
                    display.MouseCoordinatey = 7;

                }
                initial_game_code_table[display.MouseCoordinatex][display.MouseCoordinatey] = display.pieceType;
            }
			display.displayBoard(initial_game_code_table);
		}
    }
    display.close_SDL();
    return 0;     
}
