#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "piece.hpp"
class Bishop: public Piece
{
  public:
  bool isBishop = true;
  char getCodeSymbol() const;

  Bishop(bool isWhite);
  Bishop();
  ~Bishop();
	/**
    * Recebe o valor da pe�a
    *
    * @retorna o valor
    */
    int value() const;
	/**
    * Checa se a pe�a pode se mover para um dado quadrado(square).
    * @param o quadrado q pe�a esta querendo ir
    *
    */
    * @return se o movimento � v�lido
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
}; // Bispo
#endif
