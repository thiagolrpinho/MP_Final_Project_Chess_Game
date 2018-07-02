#include <SDL.h>
#include "display.hpp"

Display::Display(){
    textColor = { 0, 0, 0 };
    window = NULL;
	renderer = NULL;
    init_SDL();
}

bool Display::init_SDL() {
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			printf("Warning: Linear texture filtering not enabled!");

		//Create window
		window = SDL_CreateWindow("Moosey Chess Engine", SDL_WINDOWPOS_UNDEFINED,
					   SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, 
					   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (window == NULL) {
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Create vsynced renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
		
			}
		}
	}

	return success;
}

void Display::close_SDL() {
    //Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
}