#include "queen.hpp"
#include "board.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}

Queen::Queen()
{
}


Queen::~Queen()
{
}



int Queen::value() const
{
    return 9;
}


/// Assertivas de entrada da fun��o: 
///if(Board::getBoard()->isClearVertical(*(this->location()), location)), 
///if(Board::getBoard()->isClearVertical(*(this->location()), location)), 
///else if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
bool Queen::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
    bool move_is_valid = false;
    
    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se a rainha tiver se movendo uma reta vertica
    /// Assertiva de sa�da: garante que o movimento da rainha � v�lido
    move_is_valid = Board::getBoard()->isClearPath(actual_horizontal_coordinate,
               actual_vertical_coordinate, future_horizontal_coordinate,
               future_vertical_coordinate);

    return move_is_valid;
}


char Queen::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'r';

  } else {
    return 'R';
  }
}
