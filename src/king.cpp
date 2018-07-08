#include "king.hpp"

King::King(bool isWhite) : Piece(isWhite)
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
