#include "piece.hpp"

Piece::Piece( char is_being_created_white )
{
    isWhite = is_being_created_white;
     this->setCodeSymbol();
   
}

Piece::Piece()
{
  isWhite = true;
   this->setCodeSymbol();
}

void Piece::setBlack()
{
  isWhite = false;
}

void Piece::setCodeSymbol()
{
  code_symbol_ = 0;
}

char Piece::getCodeSymbol()
{
  return code_symbol_;
}