#include "bishop.hpp"
#include "board.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
}

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

int Bishop::value() const
{
    return 3;
}

///Assertivas de entrada: if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
bool Bishop::canMoveTo( uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
  bool move_is_valid = false;
  bool horizontal_direction_positive = actual_horizontal_coordinate < future_horizontal_coordinate;
  bool vertical_direction_positive = actual_vertical_coordinate < future_vertical_coordinate;
  uint8_t horizontal_capture_piece_coordinate;
  uint8_t vertical_capture_piece_coordinate;
  uint8_t vertical_direction, horizontal_direction;

  if( horizontal_direction_positive )
  {
    horizontal_direction = -1;
  } else {
    horizontal_direction = 1;
  }

  if( vertical_direction_positive )
  {
    vertical_direction = -1;
  } else {
    vertical_direction = 1;
  }

  horizontal_capture_piece_coordinate = future_horizontal_coordinate + horizontal_direction;
  vertical_capture_piece_coordinate = future_vertical_coordinate + vertical_direction;

  if( Board::getBoard()->isClearDiagonal(  actual_horizontal_coordinate,
                actual_vertical_coordinate,  horizontal_capture_piece_coordinate,
                vertical_capture_piece_coordinate ) )
  {
    if( !Board::getBoard()->isClearDiagonal(  actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_horizontal_coordinate,
                future_vertical_coordinate ) )
    {
      if( Board::getBoard()->getPieceAt( future_horizontal_coordinate,
                            future_vertical_coordinate )->isWhite == this->isWhite )
      {
          return false;
      } else {
          return true;
      }
    } else {
      return true;
    }
  }
    
    return move_is_valid;
}

char Bishop::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'b';

  } else {
    return 'B';
  }
  
}
