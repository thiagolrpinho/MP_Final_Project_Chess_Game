#include "piece.hpp"

Piece::Piece( char is_being_created_white )
{
    isWhite = is_being_created_white;
}

Piece::Piece()
{
  isWhite = true;
}

void Piece::setBlack()
{
  isWhite = false;
}