#include "queen.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
   this->setCodeSymbol();
}



Queen::~Queen()
{
   this->setCodeSymbol();
}


void Queen::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'r';

  } else {
    code_symbol = 'R';
  }
