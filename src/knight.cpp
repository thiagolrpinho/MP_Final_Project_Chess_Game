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

/// Assertivas de entrada da função: 
///if(abs(translationY) == 1 && abs(translationX) == 2), 
///if(abs(translationX) == 1 && abs(translationY) == 2)
bool Knight::canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    /// Assertiva de entrada que checa se o movimento do cavalo é válido
    /// movimento é válido se o cavalo se mover 1 quadrado pra frente/atrás e dois para direita/esquerda
    if(abs(translationY) == 1 && abs(translationX) == 2)
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento do cavalo é válido
    /// movimento é válido se o cavalo se mover 1 quadrado pra direita/esquerdas e dois para frente/atrás
    else if(abs(translationX) == 1 && abs(translationY) == 2)
    {
        validMove = true;
    }
    ///Assertiva de saída: é garantido que o movimento do cavalo é válido
    
    return validMove;
}

void Knight::display() const
{
    cout << _color + "N";
}


void Knight::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'c';

  } else {
    code_symbol_ = 'C';
  }
  
}
