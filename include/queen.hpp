#ifndef QUEEN_HPP
#define QUEEN_HPP
#include "piece.hpp"
class Queen: public Piece
{
  public:
  bool isQueen = true;
  char getCodeSymbol() const;

  Queen(bool isWhite);
  Queen();
  ~Queen();

	bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
    
               uint8_t future_vertical_coordinate) const;
	/**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;
}; // Rainha

#endif