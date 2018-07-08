#include "bishop.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
   this->setCodeSymbol();
}

Bishop::~Bishop()
{
   this->setCodeSymbol();
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
