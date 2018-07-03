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
        SDL_Color textColor;
    public:
        Display();
        ~Display();
        void drawBorder();
        bool init_SDL();
        void close_SDL();


};






#endif