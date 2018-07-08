#include "bishop.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
   ;
}

Bishop::~Bishop()
{
   ;
}

char  Bishop::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'b';

  } else {
    return 'B';
  }
  
}
