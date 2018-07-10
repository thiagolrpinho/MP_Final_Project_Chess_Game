#include "controller.hpp"

//calls game engine and receives new board
char movepiece( const char (&board)[8][8] ){


    return 'c';
}

//returns new board if it's valid or old one if it's not
char validateboard( const char (&board)[8][8]  ){

    return 'c';
}
/* 
//calls ai and receives and new board with it's move
char  aimove( const char (&board)[8][8]  ){

    return 0
}

//calls savegame function
void  savegame( const char (&board)[8][8]  ){
    salvarTab(&board);

}
//calls function to load board returns loaded board
char loadboard(){
    char board[8][8] =
    {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    carregaTab(&board);

    return board;

}
//calls function to edit empty board returns edited board
char editboard() {
    char board[8][8] =
    {
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'}
    };
    editar(&board);

    return board;
}


//calls function to show options for moves
char showoptions( const char (&board)[8][8]  ){

    return board;
}

//returns new standard board
char newstandardgame(){
    char board[8][8] =
    {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };

    return board;
}

//calls funtion that creates a new empty board and asks for the right pieces
char  newemptyboard(){
    //char board[8][8]=editar();

    return board;
} */
