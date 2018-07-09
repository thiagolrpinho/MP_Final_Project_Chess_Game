#include "bishop.hpp"
#include "board.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
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
    
    move_is_valid = Board::getBoard()->isClearDiagonal(  actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_horizontal_coordinate,
                future_vertical_coordinate );
    
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
