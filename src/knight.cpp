#include "knight.hpp""

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
///if(abs(translationY) == 1 && abs(translationX) == 2), 
///if(abs(translationX) == 1 && abs(translationY) == 2)
bool Knight::canMoveTouint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    /// Assertiva de entrada que checa se o movimento do cavalo � v�lido
    /// movimento � v�lido se o cavalo se mover 1 quadrado pra frente/atr�s e dois para direita/esquerda
    if(abs(translationY) == 1 && abs(translationX) == 2)
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento do cavalo � v�lido
    /// movimento � v�lido se o cavalo se mover 1 quadrado pra direita/esquerdas e dois para frente/atr�s
    else if(abs(translationX) == 1 && abs(translationY) == 2)
    {
        validMove = true;
    }
    ///Assertiva de sa�da: � garantido que o movimento do cavalo � v�lido
    
    return validMove;
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
