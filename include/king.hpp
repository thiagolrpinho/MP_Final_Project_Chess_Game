#ifndef KING_HPP
#define KING_HPP
#include "piece.hpp"
class King: public Piece
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



    /**
    *
    * Determina se o rei pode se mover para um dado quadrado
    * @param quadrado o quadrado destino
    */
    * @return se o movimento � v�lido
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
}; // Rei

#endif