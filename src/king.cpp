#include "king.hpp"

King::King(bool isWhite) : Piece(isWhite)
{
   this->setCodeSymbol();
}



King::~King()
{
   this->setCodeSymbol();
}

void King::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'k';

  } else {
    code_symbol = 'K';
  }
