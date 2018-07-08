#include "knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
}

Knight::~Knight()
{
}

void Knight::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'c';

  } else {
    code_symbol = 'C';
  }
  
}

