#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece.hpp"
class Queen: public Piece
{
  public:
  bool isQueen = true;
  char setCodeSymbol();
};

#endif