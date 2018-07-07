#include <SDL.h>
#include "display.hpp"
#include <iostream>

Display::Display(){
    textColor = { 0, 0, 0 };
    window = NULL;
	renderer = NULL;
    init_SDL();
	frameCounter = FRAME_REFRESH_RATE;
}

bool Display::init_SDL() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			printf("Warning: Linear texture filtering not enabled!");

		//Create window
		window = SDL_CreateWindow("Xadrez", SDL_WINDOWPOS_UNDEFINED,
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

Display::~Display() {
	close_SDL();
}

void Display::displayBoard(char matriz[8][8]){
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 209, 224, 255, 255);
	SDL_RenderClear(renderer);
	drawSquares(matriz);
	drawBorder();
	//Update screen
	if (frameCounter > FRAME_REFRESH_RATE) {
		SDL_RenderPresent(renderer);
		frameCounter = 0;
	}
	frameCounter++;
}

void Display::drawSquares(char matriz[8][8]) {
	int sq;
	SDL_Rect sqPos;
	for (int r = 1; r <= 8; r++) {
		for (int f = 1; f <= 8; f++) {
			sq = (f+((r-1)*8))-1;
			//Otherwise, color light
			if ((r+f)%2 == 1)			
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			//or color dark
			else 						
				SDL_SetRenderDrawColor(renderer, 0, 153, 153, 255);
			
				sqPos = {(r*SQ_SIZE)-BYSTART,	//X start
					(f*SQ_SIZE)-BXSTART,	//Y start
					SQ_SIZE, SQ_SIZE};	//Width, height of square
				SDL_RenderFillRect(renderer, &sqPos);	
				//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			
		}
	}
}

void Display::drawBorder() {
	SDL_Rect borderRect = {BXSTART, BYSTART, B_SIZE, B_SIZE};
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &borderRect);
	borderRect = {BXSTART-1, BYSTART-1, B_SIZE+2, B_SIZE+2};
	SDL_RenderDrawRect(renderer, &borderRect);
}