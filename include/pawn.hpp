#ifndef PAWN_HPP
#define PAWN_HPP
#include "restricted_piece.hpp"

typedef shared_ptr<Piece>  PPiece;

class Pawn : public RestrictedPiece
{
  public:
  bool isPawn = true;
  char getCodeSymbol() const;

  Pawn(bool isWhite);
  Pawn();
  ~Pawn();

    /**
    *
    * Pega o valor da pe�a
    * @return o valor
    */
    int value() const;

    

    /**
    * Determina se a pe�a pode se mover para o quadrado recebido baseado na geometria do movimento
    * @param quadrado o quadrado destino
    *
    * @return se o movimento � v�lido
    */
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;

 private:

    // Private attributes
    PPiece _delegate;

};
 // Pe�o
#endif