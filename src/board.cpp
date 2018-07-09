#include "board.hpp"

/*! \vertical board.cpp
    \brief Module responsible to implement encapsule square and
    implement board behaviors
*/

//! A constructor that creates a board
    /*!
        \Description Creates a new board
        with a size_of_table_ x size_of_table_
        matrix of squares each one with
        it's unique and respective coordinate.
    */
Board::Board()
{
    // Set up squares (size_of_table_ x size_of_table_)
    for(uint8_t i = 0; i < size_of_table_; i++)
    {
        for(uint8_t j = 0; j < size_of_table_; j++)
        {
            squares_[i][j].reset( new Square( i, j ) );
                //Makes each squares_ to point to a new Square
        }
    }
}

Board::~Board()
{
  // Reset squares pointers and they're deallocated
  for (uint8_t i = 0; i < size_of_table_; i++)
  {
    for (uint8_t j = 0; j < size_of_table_; j++)
    {
        squares_[i][j].reset();
    }
  }
}

//! 
    /*! Initializes Board on the first call and returns a pointer to the board
        \Description Verifies if there's already one board.
        If there no board it tries to create one and return it's value 
        stored on board_table_.
        If it cannot create, throws an Error.
        Else if there is already one board it just returns board_table_.
        \return A shared pointer to the singleton board.
        \throw Error if couldn't created board
    */
shared_ptr<Board> Board::getBoard(){
    //If there's no board, then create one.
    if( board_table_ == nullptr )
    {  
        try {
            board_table_.reset( new Board() );
            //Reset board table to new board
        } catch ( int throwned_error) {
            // If there was a failure creating board
            throw Error;
        }
    }

    return board_table_;
}

//*! Returns the square on given coordinates
    /*!
        \Description Fix evaluates if the given coordinates
        are valid then return a valid square.
        
        \param Two uint8_t lower than size_of_table_.
        \return A valid square of the given coordinates.
        \throw Error if given coordinates not valid
    */
PSquare Board::getSquareAt( uint8_t horizontal_coordinate, uint8_t vertical_coordinate )
{ 
  // If any given coordinate is greater of equal to the size of the table
  // then it's an Error.
  if( vertical_coordinate >= size_of_table_ ) throw (int) Error;
  if( horizontal_coordinate >= size_of_table_ ) throw (int) Error;

  return squares_[horizontal_coordinate][vertical_coordinate];
}

//*! Returns the piece on given coordinates
    /*!
        \Description Fix evaluates if the given coordinates
        are valid then return a valid piece
        
        \param Two uint8_t lower than size_of_table_.
        \return A valid square of the given coordinates.
        \throw Error if given coordinates not valid
    */
PPiece Board::getPieceAt( uint8_t horizontal_coordinate, uint8_t vertical_coordinate )
{ 
  // If any given coordinate is greater of equal to the size of the table
  // then it's an Error.
  if( vertical_coordinate >= size_of_table_ ) throw (int) Error;
  if( horizontal_coordinate >= size_of_table_ ) throw (int) Error;

  if( squares_[horizontal_coordinate][vertical_coordinate]->getPiece() == nullptr )
    throw (int) Error;

  return squares_[horizontal_coordinate][vertical_coordinate]->getPiece();
}

//*! Change the piece on the given square
    /*!
        \Description Tries to get a valid square
        and to change it's piece
        If it succeeds return a Success(Integer 1)
        If not return an Error(integer 0)
        
        \param Two uint8_t lower than size_of_table_ and 
                shared pointer to a valid an already created 
                Piece
        \return A Success(integer 1) or an Error(integer 0)
    */
uint8_t Board::setPieceAt( uint8_t horizontal_coordinate, 
                        uint8_t vertical_coordinate , PPiece piece_to_be_set )
{
  try {
    PSquare square_on_coordinate( 
                        Board::getBoard()->getSquareAt( horizontal_coordinate, vertical_coordinate) );
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
  uint8_t horizontal_iterator;
  shared_ptr<Board> the_actual_board( getBoard() );

  // Moving to the same square is not a valid move.
  if( actual_horizontal_coordinate == future_horizontal_coordinate ) return false;
  // Moving outside the board is not valid.
  if( future_horizontal_coordinate >= size_of_table_ ) return false;

  // Starting outside the board is not valid.
  if( actual_horizontal_coordinate >= size_of_table_ ) throw (int) Error;
  if( actual_vertical_coordinate >= size_of_table_ ) throw (int) Error;

  if( actual_horizontal_coordinate < future_horizontal_coordinate )
  {
    // Start one square ahead of the actual position and ends
    // over the last square
    most_right_coordinate = future_horizontal_coordinate + 1;
    most_left_coordinate = actual_horizontal_coordinate + 1;

  } else {

    most_right_coordinate = actual_horizontal_coordinate;
    most_left_coordinate = future_horizontal_coordinate;

  }
  
  for( horizontal_iterator= most_left_coordinate; horizontal_iterator< most_right_coordinate; horizontal_iterator++ )
  {
    if( the_actual_board->getSquareAt( horizontal_iterator, actual_vertical_coordinate )->isOccupied() == true ) return false;
  }
  return true;
} //Board::isClearHorizontal


bool Board::isClearVertical(uint8_t actual_horizontal_coordinate, 
            uint8_t actual_vertical_coordinate, uint8_t future_vertical_coordinate) const 
{
  uint8_t upper_coordinate, lower_coordinate;
  uint8_t vertical_iterator;
  shared_ptr<Board> the_actual_board( getBoard() );


  // Moving to the same square is not a valid move.
  if( actual_vertical_coordinate == future_vertical_coordinate ) return false;
  // Moving outside the board is not valid.
  if( future_vertical_coordinate >= size_of_table_ ) return false;

  // Starting outside the board is not valid.
  if( actual_horizontal_coordinate >= size_of_table_ ) throw (int) Error;
  if( actual_vertical_coordinate >= size_of_table_ ) throw (int) Error;

  if( actual_vertical_coordinate < future_vertical_coordinate )
  {
    // Start one square ahead of the actual position and ends
    // over the last square
    upper_coordinate = future_vertical_coordinate + 1;
    lower_coordinate = actual_vertical_coordinate + 1;
  } else {
    upper_coordinate = actual_vertical_coordinate;
    lower_coordinate = future_vertical_coordinate;
  }
  
  for( vertical_iterator= lower_coordinate; vertical_iterator< upper_coordinate; vertical_iterator++ )
  {
    if( the_actual_board->getSquareAt(actual_horizontal_coordinate, vertical_iterator)->isOccupied() == true ) return false;
  }
  
  return true;
} //Board::isClearVertical()

bool Board::isClearDiagonal(uint8_t actual_horizontal_coordinate,
            uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
            uint8_t future_vertical_coordinate ) const
{
  uint8_t diagonal_iterator;
  uint8_t horizontal_absolute_translation, vertical_absolute_translation;
  int8_t vertical_direction, horizontal_direction;
  bool vertical_direction_positive, horizontal_direction_positive;

  shared_ptr<Board> the_actual_board( getBoard() );

  // Moving to the same square is not a valid move.
  if( actual_horizontal_coordinate == future_horizontal_coordinate ) return false;
  if( actual_vertical_coordinate == future_vertical_coordinate ) return false;

  // Moving outside the board is not valid.
  if( future_horizontal_coordinate >= size_of_table_ ) return false;
  if( future_vertical_coordinate >= size_of_table_ ) return false;

  // Starting outside the board is not valid.
  if( actual_horizontal_coordinate >= size_of_table_ ) throw (int) Error;
  if( actual_vertical_coordinate >= size_of_table_ ) throw (int) Error;

  // The diagonal path must be 
  // | x1 - x2 | = | y1 - y2 |
  horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
  vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );

  if(  horizontal_absolute_translation != vertical_absolute_translation ) return false;


  // Here we are sure that we have a valid diagonal
  // Then we must now which will be the direction of translation.
  horizontal_direction_positive = actual_horizontal_coordinate < future_horizontal_coordinate;
  vertical_direction_positive = actual_vertical_coordinate < future_vertical_coordinate;

  if( horizontal_direction_positive )
  {
    horizontal_direction = 1;
  } else {
    horizontal_direction = -1;
  }

  if( vertical_direction_positive )
  {
    vertical_direction = 1;
  } else {
    vertical_direction = -1;
  }
  
  for ( diagonal_iterator = 1; diagonal_iterator <= abs(actual_horizontal_coordinate - future_horizontal_coordinate); 
  diagonal_iterator++ )
  { //Each iteration will be a new diagonal neighbour
    try {
      uint8_t horizontal_axis_movement = actual_horizontal_coordinate + (diagonal_iterator * horizontal_direction);
      uint8_t vertical_axis_movement = actual_vertical_coordinate + (diagonal_iterator * vertical_direction);

      if( the_actual_board->getSquareAt( horizontal_axis_movement, vertical_axis_movement )->isOccupied() == true )
        return false;

    } catch (int throwned_error )
    {
      throw (int) Error;
    }
  } // for()

  return true;
}  // Board::isClearDiagonal()

bool Board::isClearPath( uint8_t actual_horizontal_coordinate,
            uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
            uint8_t future_vertical_coordinate ) const
{
  bool vertical_is_clear, horizontal_is_clear, diagonal_is_clear;

  vertical_is_clear = Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
             actual_vertical_coordinate, future_vertical_coordinate );
  
  horizontal_is_clear = Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
             actual_vertical_coordinate, future_horizontal_coordinate );

  diagonal_is_clear = Board::getBoard()->isClearDiagonal( actual_horizontal_coordinate,
             actual_vertical_coordinate, future_horizontal_coordinate,
             future_vertical_coordinate );

  return ( vertical_is_clear | horizontal_is_clear | diagonal_is_clear );
}

bool Board::isEndRow(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate) const
{
  return (actual_vertical_coordinate == 0 || actual_vertical_coordinate == size_of_table_ - 1);
}

uint8_t Board::cleanBoard()
{
  for (uint8_t horizontal_coordinate = 0; horizontal_coordinate < size_of_table_; horizontal_coordinate++)
  {
    for( uint8_t vertical_coordinate = 0; vertical_coordinate < size_of_table_; vertical_coordinate++ )
    {
      if( squares_[horizontal_coordinate][vertical_coordinate]->deletePiece() == Error ) return Error;
    }
  }
  return Success;
}

uint8_t Board::cleanSquareAt(uint8_t horizontal_coordinate, uint8_t vertical_coordinate )
{
  if(Board::getBoard()->getSquareAt(horizontal_coordinate, vertical_coordinate)->deletePiece() == Error )
    return Error;
  
  return Success;
}
//Initializes board_table_ with nullptr
shared_ptr<Board> Board::board_table_ = nullptr;