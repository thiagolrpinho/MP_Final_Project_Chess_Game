#include "knight.hpp"

Knight::Knight(bool isWhite) : Piece(isWhite)
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

    // Moving outside the board is not valid.
    if( future_horizontal_coordinate >= size_of_table_ ) return move_is_valid;
    if( future_vertical_coordinate >= size_of_table_ ) return move_is_valid;

    horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
    vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );
    
    /// Assertiva de entrada que checa se o movimento do cavalo � v�lido
    /// movimento � v�lido se o cavalo se mover 1 quadrado pra frente/atr�s e dois para direita/esquerda
    if(abs( vertical_absolute_translation ) == 1 && abs( horizontal_absolute_translation ) == 2)
    {
        move_is_valid = true;
    }
    
    /// Assertiva de entrada que checa se o movimento do cavalo � v�lido
    /// movimento � v�lido se o cavalo se mover 1 quadrado pra direita/esquerdas e dois para frente/atr�s
    else if(abs( horizontal_absolute_translation ) == 1 && abs( vertical_absolute_translation ) == 2)
    {
        move_is_valid = true;
    }
    ///Assertiva de sa�da: � garantido que o movimento do cavalo � v�lido
    
    return move_is_valid;
}

void Knight::display() const
{
    cout << _color + "N";
}


char Knight::getCodeSymbol()
{
  if ( isWhite )
  {
    return 'c';

  } else {
    return 'C';
  }
  
  
}
