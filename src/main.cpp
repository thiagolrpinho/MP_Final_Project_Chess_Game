#include <SDL.h>
#include <iostream>
#include <display.hpp>

using namespace std;

int main( int argc, char* args[] )
{   
    bool quit = false, muted = true, start = false;
    Display display;
    SDL_Event e; //Event handler
    char initial_game_code_table[8][8] =
        {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { }, //These will be filled with 0
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
					break;

				}
			}
			display.displayBoard(initial_game_code_table);
		}
    }
    display.close_SDL();
    return 0;     
}
