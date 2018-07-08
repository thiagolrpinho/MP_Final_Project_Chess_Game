#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "piece.hpp"
class Knight: public Piece
{
  public:
  bool isKnight = true;
  char setCodeSymbol();
};

#endif