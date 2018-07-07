#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL.h>

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
    public:
        Display();
        ~Display();

        
		void drawPieces(char matriz[8][8]);
		void drawBorder();
        bool init_SDL();
        void close_SDL();
        void displayBoard(char matriz[8][8]);
        void setSpriteClips();
        void drawSquares(char matriz[8][8]);
        int getBoardXStart() { return BXSTART; };
		int getBoardYStart() { return BYSTART; };
		int getSqSize() { return SQ_SIZE; };
		int getBoardSize() { return B_SIZE; };
		

};






#endif