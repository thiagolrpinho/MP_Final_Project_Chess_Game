#include "rook.hpp"
#include "board.hpp"

Rook::Rook(bool isWhite) : RestrictedPiece(isWhite)
{
}

Rook::Rook()
{
}

Rook::~Rook()
{
}


int Rook::value() const
{
    return 5;
}


/// Assertivas de entrada da fun��o: 
/// if(Board::getBoard()->isClearVertical(*(this->location()), location))
/// if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
 
bool Rook::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
    bool move_is_valid = false;
    
    /// Assertiva de entrada que checa se o movimento da torre � v�lido
    /// o movimento � v�lido se a torre tiver se movendo em uma reta vertical
    if( Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_vertical_coordinate))
    {
        move_is_valid = true;
    /// Assertiva de entrada que checa se o movimento da torre � v�lido
    /// o movimento � v�lido se a torre tiver se movendo em uma reta horizontal
    } else if( Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_horizontal_coordinate ) )
    {
        move_is_valid = true;
    }
    
    /// Assertiva de sa�da: � garantido que o movimento da torre � v�lido
    return move_is_valid;
}



char Rook::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 't';

  } else {
    return 'T';
  }
  
}
