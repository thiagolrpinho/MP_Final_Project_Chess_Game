#include "rook.hpp"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
   this->setCodeSymbol();
}


Rook::~Rook()
{
   this->setCodeSymbol();
}

void Rook::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 't';

  } else {
    code_symbol = 'T';
  }
  
}
