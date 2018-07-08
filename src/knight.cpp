#include "knight.h"

Knight::Knight(bool isWhite) : Piece(isWhite)
{
   this->setCodeSymbol();
}

Knight::~Knight()
{
  this->setCodeSymbol();
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

