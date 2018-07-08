#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"

Pawn::Pawn(bool isWhite) : Piece(isWhite)
{
   ;
}

Pawn::Pawn() : Piece()
{
   ;
}

Pawn::~Pawn()
{
   ;
}

char  Pawn::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'p';

  } else {
    return 'P';
  }
  
}
