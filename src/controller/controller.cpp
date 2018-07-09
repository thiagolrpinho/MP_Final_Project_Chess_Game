#include <memory>
#include "../Salvar.cpp"
#include "../engine.cpp"
#include "../Editar.cpp"
using std::unique_ptr;
typedef unique_ptr<char*> Matrix;


//calls game engine and receives new board
Matrix movepiece(char board[8][8]){
    Matrix newboard = &board[8][8];



    return board;
}

//returns true or false if the board is valid
bool validateboard(char board[8][8]){

    return validation;
}

//calls ai and receives and new board with it's move
char  aimove(char board[8][8]){

    return board;
}

//calls savegame function
void  savegame(char board[8][8]){
    salvarTab(&board);


}
//calls function to load board
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
    char board[8][8]=carregaTab(&board);

    return board;

}

//calls function to show options for moves
Matrix showoptions(char board[8][8]){

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
    char board[8][8]=editar();

    return board;
}
