#include <iostream>
#include <string.h>
#include "controller.hpp"

using namespace std;

bool quit = false, muted = true, start = false;

int main( int argc, char* args[] )
{   
    bool valid_turn;
    char new_move[2];
    char piece_to_be_moved[2];
    char temp;
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

        Engine::getEngine()->readCodeTable( game_code_table );
    do {
        PCodeTable code_table = Engine::getEngine()->returnCodeTable();
        char matrix[8][8];
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                matrix[i][j] = code_table[i][j];
            }
        Engine::getEngine()->printCodeTable( matrix );
        scanf("%d", &temp);
        scanf("%2s", &piece_to_be_moved);
        scanf("%2s", &new_move);
        cout << piece_to_be_moved[0] << " e " << piece_to_be_moved[1] << endl;
        cout << new_move[0] << " e " << new_move[1] << endl;

        code_table = Controller::getController()->interfaceToCodeTable(piece_to_be_moved, new_move);
        if(!code_table) return 3;
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                matrix[i][j] = code_table[i][j];
            }
        valid_turn = Controller::getController()->tryTurn( matrix ); 
    } while( valid_turn );
    return 0;     
}
