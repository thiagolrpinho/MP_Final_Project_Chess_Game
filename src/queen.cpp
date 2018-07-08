#include "queen.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}



Queen::~Queen()
{
}


void Queen::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'r';

  } else {
    code_symbol = 'R';
  }
