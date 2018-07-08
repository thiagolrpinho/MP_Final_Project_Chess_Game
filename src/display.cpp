#include <SDL.h>
#include "display.hpp"
#include <iostream>

Display::Display(){
    textColor = { 0, 0, 0 };
    window = NULL;
		renderer = NULL;
    init_SDL();
		loadMedia();
		setSpriteClips();
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
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags)) {
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not be initialized.\n");
					success = false;
				}
		
			}
		}
	}

	return success;
}

void Display::close_SDL() {
	spriteSheetTexture.free();
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
	drawPieces(matriz);
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

bool Display::loadMedia() {
	bool success = true;
	spriteSheetTexture.loadFromFile(renderer, "spritesheet2.bmp");
	if (spriteSheetTexture.texture == NULL){
		success = false;
	}
	SDL_Surface* icon = IMG_Load("icon.png");	
	SDL_SetWindowIcon(window, icon);
	return success;
}

void Display::setSpriteClips() {
	for (int i = 0; i < 12; i++) {
		spriteClips[i].x = i%6*SQ_SIZE;
		spriteClips[i].y = i/6*SQ_SIZE;
		spriteClips[i].w = SQ_SIZE;
		spriteClips[i].h = SQ_SIZE;
	}
}

void Display::drawPieces(char matriz[8][8]) {

	int p, sq, x, y, putOnTop = -1;
	SDL_Rect sqPos;
	SDL_Rect clipSq, pOTClipSq;
	for (int r = 1; r <= 8; r++) {
		for (int f = 1; f <= 8; f++) {
			sq = (f)+((r-1)*8)-1;
			sqPos = {(r*SQ_SIZE)-BYSTART, 	//X start
				 (f*SQ_SIZE)-BXSTART, 	//Y start
				 SQ_SIZE, SQ_SIZE};	//Width, height of square
		

			if (matriz[r-1][f-1] == 'T')
				clipSq = spriteClips[wRook];		
		    else if (matriz[r-1][f-1] == 'C')
				clipSq = spriteClips[wKnight];		
		    else if (matriz[r-1][f-1] == 'B')
				clipSq = spriteClips[wBishop];		
		    else if (matriz[r-1][f-1] == 'R')
				clipSq = spriteClips[wQueen];		
		    else if (matriz[r-1][f-1] == 'Z')
				clipSq = spriteClips[wKing];		
		    else if (matriz[r-1][f-1] == 'P')
				clipSq = spriteClips[wPawn];
			
					
			if ( matriz[r-1][f-1] == 't')
				clipSq = spriteClips[bRook];		
		    else if ( matriz[r-1][f-1] == 'c')
				clipSq = spriteClips[bKnight];		
		    else if ( matriz[r-1][f-1] == 'b')
				clipSq = spriteClips[bBishop];		
		    else if ( matriz[r-1][f-1] == 'r')
				clipSq = spriteClips[bQueen];		
		    else if ( matriz[r-1][f-1] == 'z')
				clipSq = spriteClips[bKing];		
		    else if ( matriz[r-1][f-1] == 'p')
				clipSq = spriteClips[bPawn];	

			if ( matriz[r-1][f-1] != 0){
				//Save piece being dragged, to rerender on top
					spriteSheetTexture.render(renderer, sqPos.x, sqPos.y, &clipSq);
			}

			if (putOnTop != -1) { //Rerender piece being dragged
				SDL_GetMouseState(&x, &y);
				if (x < BXSTART + SQ_SIZE/2) 
					x = BXSTART + SQ_SIZE/2;
				if (x > BXSTART + B_SIZE - SQ_SIZE/2) 
					x = BXSTART + B_SIZE - SQ_SIZE/2;
				if (y < BYSTART + SQ_SIZE/2) 
					y = BYSTART + SQ_SIZE/2;
				if (y > BYSTART + B_SIZE - SQ_SIZE/2) 
					y = BYSTART + B_SIZE - SQ_SIZE/2;
				spriteSheetTexture.render(renderer, x-SQ_SIZE/2, y-SQ_SIZE/2, &pOTClipSq);
	}
			
		}
	}
	
}