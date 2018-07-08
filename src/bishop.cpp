#include "bishop.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
   ;
}

Bishop::~Bishop()
{
   ;
}

void Bishop::setCodeSymbol()
{
  if ( isWhite )
  {
    return 'b';

  } else {
    return 'B';
  }
  
}
