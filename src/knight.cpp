#include "knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
   ;
}

Knight::~Knight()
{
  ;
}

void Knight::setCodeSymbol()
{
  if ( isWhite )
  {
    return 'c';

  } else {
    return 'C';
  }
  
}

