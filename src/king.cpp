#include "king.hpp"

King::King(bool isWhite) : Piece(isWhite)
{
}



King::~King()
{
}

void King::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'k';

  } else {
    code_symbol = 'K';
  }
