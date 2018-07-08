#ifndef KING_HPP
#define KING_HPP
#include "piece.hpp"
class King: public Piece
{
  public:
  bool isKing = true;
  char getCodeSymbol() const;
};

#endif