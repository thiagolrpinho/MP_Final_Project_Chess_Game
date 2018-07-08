#include "rook.hpp"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
   ;
}


Rook::~Rook()
{
   ;
}

void Rook::setCodeSymbol()
{
  if ( isWhite )
  {
    return 't';

  } else {
    return 'T';
  }
  
}
