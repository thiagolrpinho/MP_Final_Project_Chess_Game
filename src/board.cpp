#include "board.hpp"

/*! \vertical board.cpp
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
    for(uint8_t i = 0; i < _size_of_table; i++)
    {
        for(uint8_t j = 0; j < _size_of_table; j++)
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
        
        \param Two uint8_t lower than _size_of_table.
        \return A valid board square of the given coordinates.
        \throw Error if given coordinates not valid
    */
  PBoardSquare Board::getBoardSquareAt( uint8_t vertical_coordinate, uint8_t horizontal_coordinate  )
  { 
    // If any given coordinate is greater of equal to the size of the table
    // then it's an Error.
    if( vertical_coordinate >= _size_of_table ) throw (int) Error;
    if( horizontal_coordinate >= _size_of_table ) throw (int) Error;

    return _board_square_matrix[vertical_coordinate][horizontal_coordinate];
  }

//*! Change the piece on the given board square
    /*!
        \Description Tries to get a valid board square
        and to change it's piece
        If it succeds return a Success(Integer 1)
        If not return an Error(integer 0)
        
        \param Two uint8_t lower than _size_of_table and 
                shared pointer to a valid an already created 
                Piece
        \return A Success(integer 1) or an Error(integer 0)
    */
  uint8_t Board::setPieceAt( uint8_t horizontal_coordinate, 
                          uint8_t vertical_coordinate , PPiece piece_to_be_set )
  {
    try {
      PBoardSquare square_on_coordinate( 
                          Board::getBoard()->getBoardSquareAt( horizontal_coordinate, vertical_coordinate) );
      if( square_on_coordinate->setPiece( piece_to_be_set ) == Error ) return Error;
    } catch (int throwned_error ) {
      return Error;
    }

    return Success;
              
  }

  bool Board::isClearHorizontal(uint8_t actual_horizontal_coordinate, 
              uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate) const
  {
    uint8_t most_right_coordinate, most_left_coordinate;
    shared_ptr<Board> the_actual_board( getBoard() );

    if( actual_horizontal_coordinate < future_horizontal_coordinate )
    {

      most_right_coordinate = future_horizontal_coordinate;
      most_left_coordinate = actual_horizontal_coordinate;

    } else {

      most_right_coordinate = actual_horizontal_coordinate;
      most_left_coordinate = future_horizontal_coordinate;

    }
    
    for( uint8_t i = most_left_coordinate + 1; i < most_right_coordinate; i++ )
    {
      if( the_actual_board->getBoardSquareAt( i, actual_vertical_coordinate )->isOccupied() == true ) return false;
    }
    return true;
  }

  bool Board::isClearVertical(uint8_t actual_horizontal_coordinate, 
              uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate) const 
  {
    return false;
  }
//Initializes _board_table with nullptr
shared_ptr<Board> Board::_board_table = nullptr;