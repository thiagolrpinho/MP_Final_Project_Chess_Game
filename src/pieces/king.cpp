#include "king.hpp"
#include "engine.hpp"

King::King(bool isWhite) : RestrictedPiece(isWhite)
{
}

King::King() : RestrictedPiece()
{
}


King::~King()
{
}



int King::value() const
{
    return 0;
}


/// Assertivas de entrada da fun��o:
/// if(abs(vertical_absolute_translation) == 1 && horizontal_absolute_translation == 0),
/// if(abs(horizontal_absolute_translation) == 1 && vertical_absolute_translation == 0),
/// if(abs(horizontal_absolute_translation) == 1 && abs(vertical_absolute_translation) == 1)
bool King::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const
{
    bool validMove = false;
    uint8_t horizontal_absolute_translation, vertical_absolute_translation;

    horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
    vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );
    

    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se o rei tiver se movendo um quadrado para frente/atr�s
    if( abs(vertical_absolute_translation) == 1 && horizontal_absolute_translation == 0 )
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se o rei tiver se movendo um quadrado para direita/esquerda
    else if( abs(horizontal_absolute_translation) == 1 && vertical_absolute_translation == 0 )
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se o rei tiver se movendo um quadrado em uma diagonal
    else if( abs(horizontal_absolute_translation) == 1 && abs(vertical_absolute_translation) == 1 )
    {
        validMove = true;
    }
    
    /// Assertiva de sa�da: � garantido que o movimento do rei ser� v�lido
    return validMove;
}


char King::getCodeSymbol() const 
{
  if ( isWhite )
  {
    return 'z';

  } else {
    return 'Z';
  }
}

bool King::inCheck() 
{
  bool check = false;
  uint8_t king_horizontal_coordinate, king_vertical_coordinate;
  uint8_t king_code;
  if( isWhite ){
    king_code = 'z';
  } else {
    king_code = 'Z';
  }

  PCodeTable actual_board = Engine::getEngine()->returnCodeTable();
  
/*   char code_table[8][8];

  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      code_table[vertical][horizontal] = actual_board[vertical][horizontal];
    }
  }

  Engine::getEngine()->printCodeTable( code_table ); */

  
 for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      if ( actual_board[vertical][horizontal] == king_code )
      {
        king_horizontal_coordinate = horizontal;
        king_vertical_coordinate = vertical;
        break;
      }
    }
  }

  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      if ( actual_board[vertical][horizontal] != 0 || actual_board[vertical][horizontal] != king_code )
      {
        if( actual_board[vertical][horizontal] < 'Z' && isWhite ) {
          if( Board::getBoard()->getSquareAt( horizontal,
            vertical )->isOccupied() ) 
            {
              if( Board::getBoard()->getPieceAt( horizontal,
                    vertical )->canMoveTo( horizontal,
                    vertical, king_horizontal_coordinate,
                    king_vertical_coordinate ) == true ) return true;
            }
        } else if ( actual_board[vertical][horizontal] >= 'a' && !isWhite ) 
        {
          if( Board::getBoard()->getSquareAt( horizontal,
              vertical )->isOccupied() ) 
          {
            if( Board::getBoard()->getPieceAt( horizontal,
                vertical )->canMoveTo( horizontal,
                vertical, king_horizontal_coordinate,
                king_vertical_coordinate ) == true ) return true;
          }
        }
      }
    }
  }

  return check; 
}