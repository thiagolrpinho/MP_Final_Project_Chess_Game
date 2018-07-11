#include "piece.hpp"

/// Assertiva de entrada da fun��o: if(isWhite)
Piece::Piece(bool is_being_created_white)
{
  isWhite = is_being_created_white;
}

Piece::Piece()
{
  isWhite = true;
}

Piece::~Piece()
{
}


void Piece::setBlack()
{
  isWhite = false;
}