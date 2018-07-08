#include "king.hpp"

King::King(bool isWhite) : Piece(isWhite)
{
   ;
}



King::~King()
{
   ;
}

void King::setCodeSymbol()
{
  if ( isWhite )
  {
    return 'k';

  } else {
    return 'K';
  }
