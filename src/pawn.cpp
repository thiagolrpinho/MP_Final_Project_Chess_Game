#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"

Pawn::Pawn(bool isWhite) : Piece(isWhite)
{
}

Pawn::~Pawn()
{
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
