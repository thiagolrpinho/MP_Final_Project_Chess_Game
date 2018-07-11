#include "knight.hpp"
#include "board.hpp"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
}

Knight::Knight()
{
}

Knight::~Knight()
{
}

int Knight::value() const
{
    return 3;
}

/// Assertivas de entrada da fun��o: 
///if(abs( vertical_absolute_translation ) == 1 && abs( horizontal_absolute_translation ) == 2), 
///if(abs( horizontal_absolute_translation ) == 1 && abs( vertical_absolute_translation ) == 2)
bool Knight::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
    bool move_is_valid = false;
    uint8_t horizontal_absolute_translation, vertical_absolute_translation;
    // Moving outside the board is not valid.
    horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
    vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );
    
    /// Assertiva de entrada que checa se o movimento do cavalo � v�lido
    /// movimento � v�lido se o cavalo se mover 1 quadrado pra frente/atr�s e dois para direita/esquerda
    if(abs( vertical_absolute_translation ) == 1 && abs( horizontal_absolute_translation ) == 2)
    {   
        if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied() )
        {
            if( Board::getBoard()->getPieceAt( future_horizontal_coordinate,  future_vertical_coordinate )->isWhite == isWhite )
            {
                return false;
            } else {
                return true;
            }

        } else {
        return true;
      }
    }
    
    /// Assertiva de entrada que checa se o movimento do cavalo � v�lido
    /// movimento � v�lido se o cavalo se mover 1 quadrado pra direita/esquerdas e dois para frente/atr�s
    else if(abs( horizontal_absolute_translation ) == 1 && abs( vertical_absolute_translation ) == 2)
    {
      if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied() )
      {
        if( Board::getBoard()->getPieceAt( future_horizontal_coordinate,  future_vertical_coordinate )->isWhite == isWhite )
        {
            return false;
        } else {
            return true;
        }

      } else {
        return true;
      }
      move_is_valid = true;
    }
    ///Assertiva de sa�da: � garantido que o movimento do cavalo � v�lido
    
    return move_is_valid;
}


char Knight::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'c';

  } else {
    return 'C';
  }
  
  
}
