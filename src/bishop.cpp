#include "bishop.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
}

Bishop::~Bishop()
{
}

void Bishop::setCodeSymbol()
{
  if ( isWhite )
  {
    code_symbol_= 'b';

  } else {
    code_symbol = 'B';
  }
  
}
