#include "rook.hpp"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
}


Rook::~Rook()
{
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
