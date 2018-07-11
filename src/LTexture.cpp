//#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "LTexture.hpp"

#ifndef SDL_INCLUDES                                                       
#define SDL_INCLUDES                                                       
#include <SDL2/SDL_image.h>                                                
#include <SDL2/SDL.h>                                                      
#endif 

LTexture::LTexture() {
	texture = NULL;
	width = 0;
	height = 0;
}

LTexture::~LTexture() {
	free();
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path) {
	free(); //Get rid of old texture
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 128, 128));
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		}
		else {
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	texture = newTexture;
	return (texture != NULL);
}

bool LTexture::loadFromRenderedText(SDL_Renderer* renderer, std::string textureText, SDL_Color textColor, TTF_Font* font) {
	free();	
	
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, textureText.c_str(), textColor);
	if (textSurface == NULL) {
		std::cout << "Unable to render text surface.\n";
	}
	else {
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (texture == NULL) {
			std::cout << "Unable to create texture from rendered text.\n";
		}
		else {
			width = textSurface->w;
			height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	
	return texture != NULL;
}

void LTexture::free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(texture, blending);
}

void LTexture::setAlpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

void LTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderQuad = {x, y, width, height};
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth() {
	return width;
}

int LTexture::getHeight() {
	return height;
}