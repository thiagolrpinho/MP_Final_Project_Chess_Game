#ifndef PAWN_HPP
#define PAWN_HPP
#include "piece.hpp"

class Pawn: public Piece
{
  public:
  bool isPawn = true;
  bool isWhite = true;

  Pawn( bool is_created_as_a_White_piece ){
    isWhite = is_created_as_a_White_piece;
  };

};

#endif