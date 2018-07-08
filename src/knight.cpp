#include "knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
   ;
}

Knight::~Knight()
{
  ;
}

char  Knight::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'c';

  } else {
    return 'C';
  }
  
}

