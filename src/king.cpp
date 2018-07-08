#include "king.hpp"

King::King(bool isWhite) : RestrictedPiece(isWhite)
{
}



King::~King()
{
}



int King::value() const
{
    return 0;
}


/// Assertivas de entrada da função:
/// if(abs(translationY) == 1 && translationX == 0),
/// if(abs(translationX) == 1 && translationY == 0),
/// if(abs(translationX) == 1 && abs(translationY) == 1)
bool King::canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();
    
    /// Assertiva de entrada que checa se o movimento é válido
    /// movimento é válido se o rei tiver se movendo um quadrado para frente/atrás
    if(abs(translationY) == 1 && translationX == 0)
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento é válido
    /// movimento é válido se o rei tiver se movendo um quadrado para direita/esquerda
    else if(abs(translationX) == 1 && translationY == 0)
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento é válido
    /// movimento é válido se o rei tiver se movendo um quadrado em uma diagonal
    else if(abs(translationX) == 1 && abs(translationY) == 1)
    {
        validMove = true;
    }
    
    /// Assertiva de saída: é garantido que o movimento do rei será válido
    return validMove;
}



void King::display() const
{
    cout << _color + "K";
}


void King::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'z';

  } else {
    code_symbol_ = 'Z';
  }
