#include "knight.hpp"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
   ;
}

Knight::Knight() : Piece()
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

