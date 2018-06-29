#include "board.hpp"

Board::Board()
{
    // Set up board squares (_DIMENSION x _DIMENSION)
    for(unsigned short int i = 0; i < 8; i++)
    {
        for(unsigned short int j = 0; j < 8; j++)
        {
            board_square_matrix_[i][j] = new BoardSquare(i,j);
        }
    }
}

Board* Board::getBoard(){
    //If there's no board, then create one.
    if(board_)
    {
        _board_table = new Board();
    }
    return _board_table;
}
