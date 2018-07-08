#include "rook.hpp"

Rook::Rook(bool isWhite) : RestrictedPiece(isWhite)
{
}


Rook::~Rook()
{
}


int Rook::value() const
{
    return 5;
}


/// Assertivas de entrada da função: 
/// if(Board::getBoard()->isClearVertical(*(this->location()), location))
/// if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
 
bool Rook::canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const
{
    bool validMove = false;
    
    /// Assertiva de entrada que checa se o movimento da torre é válido
    /// o movimento é válido se a torre tiver se movendo em uma reta vertical
    if(Board::getBoard()->isClearVertical(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento da torre é válido
    /// o movimento é válido se a torre tiver se movendo em uma reta horizontal
    else if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de saída: é garantido que o movimento da torre é válido
    return validMove;
}


void Rook::display() const
{
    cout << _color + "R";
}



void Rook::setCodeSymbol()
{
  if ( isWhite() )
  {
    code_symbol_= 't';

  } else {
    code_symbol_ = 'T';
  }
  
}
