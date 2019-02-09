#include <iostream>
#include <string.h>
#include "controller.hpp"

using namespace std;

bool quit = false, muted = true, start = false;

int main( int argc, char* args[] )
{   
    bool valid_turn;
    char game_code_table[8][8] =
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

        Engine::getEngine( game_code_table );
    
    do {
        cin >> game_code_table;
        Controlle::getController()->tryTurn( game_code_table ); 
    } while( valid_turn );
    return 0;     
}
