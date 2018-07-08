#include "queen.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
   ;
}

Queen::Queen() : Piece()
{
   ;
}


Queen::~Queen()
{
   ;
}


char Queen::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'r';

  } else {
    return 'R';
  }
}