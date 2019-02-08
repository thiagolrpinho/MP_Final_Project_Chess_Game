#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"
#include "square.hpp"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _delegate(NULL)
{
}

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}



int Pawn::value() const
{
    return 1;
}



///Assertiva de entrada da fun��o: if(!hasMoved() && vertical_absolute_translantion == 2 && horizontal_absolute_translation == 0 && Board::getBoard()->isClearVertical(*(this->location()), location))
bool Pawn::canMoveTo( uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
    uint8_t horizontal_absolute_translation, vertical_absolute_translation;
    int8_t vertical_direction, horizontal_direction;
    bool validMove = false;
    
    horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
    vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );
    
    // andar para frente significa andar para atras do ponto de vista das pe�as pretas
    if(!isWhite )
    {
        vertical_direction = -1;
    } else {
        vertical_direction = 1;
    }
    
    if( horizontal_absolute_translation == 0) //If it's only a vertical movement
    {
        // A pawn can move two squares only if it hasn't been moved
        if( vertical_absolute_translation == 2 ) 
        {   
           if( actual_vertical_coordinate == 1 || actual_vertical_coordinate == 6 ) //
           {
            // The path has to be clear till that square
            if( Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
             actual_vertical_coordinate, future_vertical_coordinate ) ) return true;
           }
        } else if ( vertical_absolute_translation == 1 )
        {
            // The path has to be clear till that square
            if( Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
             actual_vertical_coordinate, future_vertical_coordinate ) )  return true;
        }
    // When eating another piece, pawn can move diagonaly
    } else if ( horizontal_absolute_translation == 1 && vertical_absolute_translation == 1 )
    {
        if(isWhite) { 
            if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied()
                && vertical_direction == 1  )
            {
                return true;
            }
        } else {
            if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied()
             && vertical_direction == -1 )
            {
                return true;
            }

        }
    }

    return false;
}

char Pawn::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'p';

  } else {
    return 'P';
  }
  
}
