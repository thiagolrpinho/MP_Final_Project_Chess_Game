#ifndef ROOK_HPP
#define ROOK_HPP
#include "piece.hpp"

class Rook: public Piece
{
  public:
  bool isRook = true;
  char getCodeSymbol() const;

  Rook(bool isWhite);
  Rook();
  ~Rook();
};

#endif