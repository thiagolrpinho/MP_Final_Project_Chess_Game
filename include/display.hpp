#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.hpp"



//GAME CONTROL
extern bool quit, muted, start;

enum PieceSprite {
	noPiece = -1,
	wRook = 0, wKnight, wBishop, wQueen, wKing, wPawn,
	bRook, bKnight, bBishop, bQueen, bKing, bPawn
};

class Display{
    private:
        SDL_Window* window;
		SDL_Renderer* renderer;
		const static int SCREEN_W = 1250;
		const static int SCREEN_H = 700;
        const static int B_SIZE = 600, SQ_SIZE = 75, BXSTART = 50, BYSTART = 25;
        SDL_Color textColor;
        int frameCounter;
		const static int FRAME_REFRESH_RATE = 8;
        SDL_Rect spriteClips[12];
        LTexture spriteSheetTexture;
        bool dragging = false;
    public:
        Display();
        ~Display();
        char pieceType;
        int pieceCoordinatex,pieceCoordinatey=0;
        int MouseCoordinatex,MouseCoordinatey=0;
        void setDragging(bool x) { dragging = x; };
        bool getDragging() const { return dragging; };
		void drawPieces(char matriz[8][8]);
		void drawBorder();
        bool init_SDL();
        bool loadMedia();
        void close_SDL();
        void displayBoard(char matriz[8][8]);
        void setSpriteClips();
        void drawSquares(char matriz[8][8]);
        int getBoardXStart() { return BXSTART; };
		int getBoardYStart() { return BYSTART; };
		int getSqSize() { return SQ_SIZE; };
		int getBoardSize() { return B_SIZE; };
        SDL_Texture* loadTexture(std::string path);
		

};






#endif