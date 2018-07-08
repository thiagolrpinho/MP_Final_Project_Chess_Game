#include "queen.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
   ;
}



Queen::~Queen()
{
   ;
}


char Queen::setCodeSymbol()
{
  if ( isWhite )
  {
    return 'r';

  } else {
    return 'R';
  }
