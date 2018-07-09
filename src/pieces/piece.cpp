#include "piece.hpp"

/// Assertiva de entrada da fun��o: if(isWhite)
Piece::Piece(bool isWhite) : _isWhite(isWhite)
{
}

Piece::Piece()
{
  isWhite = true;
}

Piece::~Piece()
{
}

bool Piece::isWhite() const
{
    return _isWhite;
}
}

void Piece::setBlack()
{
  isWhite = false;
}