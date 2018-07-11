#ifndef ROOK_HPP
#define ROOK_HPP
#include "restricted_piece.hpp"

class Rook: public RestrictedPiece
{
  public:
  bool isRook = true;
  char getCodeSymbol() const;

  Rook(bool isWhite);
  Rook();
  ~Rook();
	/**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;
	

    
	/**
    * Determina se pe�a pode se mover pra um dado quadrado
    *
    * @param quadrado o quadrado destino
    * @return se o movimento � legal
    */
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
   
}; // Torre
#endif
