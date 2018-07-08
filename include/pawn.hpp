#ifndef PAWN_HPP
#define PAWN_HPP
#include "piece.hpp"

class Pawn: public Piece
{
  public:
  bool isPawn = true;
  char setCodeSymbol();

};

#endif