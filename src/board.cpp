#include "board.hpp"

Board::Board()
{
    // Set up board squares (_DIMENSION x _DIMENSION)
    for(unsigned short int i = 0; i < _size_of_table; i++)
    {
        for(unsigned short int j = 0; j < _size_of_table; j++)
        {
            _board_square_matrix[i][j] = new BoardSquare( i, j );
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