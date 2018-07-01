#include "board.hpp"

/*! \file board.cpp
    \brief Module responsible to implement encapsule board square and
    implement board behaviors
*/

//! A constructor that creates a board
    /*!
        \Description Creates a new board
        with a _size_of_table x _size_of_table
        matrix of board squares each one with
        it's unique and respective coordinate.
    */
Board::Board()
{
    // Set up board squares (_size_of_table x _size_of_table)
    for(unsigned short int i = 0; i < _size_of_table; i++)
    {
        for(unsigned short int j = 0; j < _size_of_table; j++)
        {
            _board_square_matrix[i][j].reset( new BoardSquare( i, j ) );
                //Makes each _board_square_matrix to point to a new Board Square
        }
    }
}

//! 
    /*! Initializes Board on the first call and returns a pointer to the board
        \Description Verifies if there's already one board.
        If there no board it tries to create one and return it's value 
        stored on _board_table.
        If it cannot create, throws an Error.
        Else if there is already one board it just returns _board_table.
        \return A shared pointer to the singleton board.
        \throw Error if couldn't created board
    */
shared_ptr<Board> Board::getBoard(){
    //If there's no board, then create one.
    if( _board_table == nullptr )
    {  
        try {
            _board_table.reset( new Board() );
            //Reset board table to new board
        } catch ( int throwned_error) {
            // If there was a failure creating board
            throw Error;
        }
    }

    return _board_table;
}

//*! Returns the board square on given coordinates
    /*!
        \Description Fix evaluates if the given coordinates
        are valid then return a valid board square.
        
        \param Two unsigned int lower than _size_of_table.
        \return A valid board square of the given coordinates.
        \throw Error if given coordinates not valid
    */
  PBoardSquare Board::getBoardSquareAt( unsigned int file_coordinate, unsigned int rank_coordinate  )
  { 
      // If any given coordinate is greater of equal to the size of the table
      // then it's an Error.
      if( file_coordinate >= _size_of_table ) throw (int) Error;
      if( rank_coordinate >= _size_of_table ) throw (int) Error;
      
      return _board_square_matrix[file_coordinate][rank_coordinate];
  }

//Initializes _board_table with nullptr
shared_ptr<Board> Board::_board_table = nullptr;