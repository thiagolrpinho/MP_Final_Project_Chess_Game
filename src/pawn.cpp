#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"

Pawn::Pawn(bool isWhite) : Piece(isWhite)
{
   this->setCodeSymbol();
}

Pawn::~Pawn()
{
   this->setCodeSymbol();
}

void Pawn::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'p';

  } else {
    code_symbol = 'P';
  }
  
}
