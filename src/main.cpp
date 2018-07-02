#include <SDL.h>
#include <iostream>
using namespace std;

const int WIDTH = 800, HEIGHT = 600;
int main( int argc, char* args[] )
{   
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    //Start SDL
    if(SDL_Init( SDL_INIT_VIDEO )<0){
        std::cout << "SDL could not initialize" << SDL_GetError( ) << std::endl;
    }

    window = SDL_CreateWindow( "Hello SDL World",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI);

    if( NULL == window){
        std::cout << "Could not create window:" << SDL_GetError( ) << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Event windowEvent;

    while(true){
        if (SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}
