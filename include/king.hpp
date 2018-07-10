#ifndef KING_HPP
#define KING_HPP
#include "restricted_piece.hpp"

class King: public RestrictedPiece
{
  public:
  bool isKing = true;
  char getCodeSymbol() const;

  King(bool isWhite);
  King();
  ~King();
	/**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;

    bool inCheck();

    /**
    *
    * Determina se o rei pode se mover para um dado quadrado
    * @param quadrado o quadrado destino
    */
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
}; // Rei

#endif