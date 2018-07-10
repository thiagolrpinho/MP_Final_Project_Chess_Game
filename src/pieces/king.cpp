#include "king.hpp"

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
 return false;
}