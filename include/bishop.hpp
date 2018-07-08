#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "piece.hpp"
class Bishop: public Piece
{
  public:
  bool isBishop = true;
  char setCodeSymbol();
};

#endif