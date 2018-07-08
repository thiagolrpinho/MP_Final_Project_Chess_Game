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


/// Assertivas de entrada da fun��o: 
/// if(Board::getBoard()->isClearVertical(*(this->location()), location))
/// if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
 
bool Rook::canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const
{
    bool validMove = false;
    
    /// Assertiva de entrada que checa se o movimento da torre � v�lido
    /// o movimento � v�lido se a torre tiver se movendo em uma reta vertical
    if(Board::getBoard()->isClearVertical(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento da torre � v�lido
    /// o movimento � v�lido se a torre tiver se movendo em uma reta horizontal
    else if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de sa�da: � garantido que o movimento da torre � v�lido
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
