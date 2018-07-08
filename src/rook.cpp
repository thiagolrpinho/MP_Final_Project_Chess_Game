#include "rook.hpp"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
   ;
}


Rook::~Rook()
{
   ;
}

char Rook::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 't';

  } else {
    return 'T';
  }
  
}
