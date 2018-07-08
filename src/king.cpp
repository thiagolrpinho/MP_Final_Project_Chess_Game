#include "king.hpp"

King::King(bool isWhite) : Piece(isWhite)
{
   ;
}

King::King() : Piece()
{
   ;
}


King::~King()
{
   ;
}

char  King::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'k';

  } else {
    return 'K';
  }
}