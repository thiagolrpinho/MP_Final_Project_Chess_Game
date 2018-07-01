#include "board.hpp"

Board::Board()
{
    // Set up board squares (_DIMENSION x _DIMENSION)
    for(unsigned short int i = 0; i < _size_of_table; i++)
    {
        for(unsigned short int j = 0; j < _size_of_table; j++)
        {
            _board_square_matrix[i][j].reset( new BoardSquare( i, j ) );
                //Makes each _board_square_matrix to point to a new Board Square
        }
    }
}

shared_ptr<Board> Board::getBoard(){
    //If there's no board, then create one.
    if( _board_table == nullptr )
    {  
        try {
            _board_table.reset( new Board() );
            //Reset board table to new board
        } catch ( int throwned_error) {
            if ( throwned_error == Error) throw Error;
        }
    }
    return _board_table;
}

//Initializes _board_table with nullptr
shared_ptr<Board> Board::_board_table = nullptr;