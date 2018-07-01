#include "board.hpp"

Board::Board()
{
    // Set up board squares (_DIMENSION x _DIMENSION)
    for(unsigned short int i = 1; i <= 8; i++)
    {
        for(unsigned short int j = 1; j <= 8; j++)
        {
            _board_square_matrix[i-1][j-1] = new BoardSquare( i, j );
        }
    }
}

Board* Board::getBoard(){
    //If there's no board, then create one.
    if( _board_table == nullptr )
    {  
        try {
            _board_table = new Board();
        } catch ( int throwned_error) {
            if ( throwned_error == Error) throw Error;
            return (Board*) 1;
        }
    }
    return _board_table;
}

Board* Board::_board_table = nullptr;