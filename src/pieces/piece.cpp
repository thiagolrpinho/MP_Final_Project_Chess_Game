#include "piece.hpp"

/// Assertiva de entrada da fun��o: if(isWhite)
Piece::Piece(bool isWhite)
{
  isWhite = isWhite;
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