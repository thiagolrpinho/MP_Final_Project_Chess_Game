#ifndef KNIGHT_HPP
#define KNIGHT_HPP
#include "piece.hpp"
class Knight: public Piece
{
  public:
  bool isKnight = true;
  char getCodeSymbol() const;

  Knight(bool isWhite);
  Knight();
  ~Knight();
    * Pega valor da pe�a
    * @return the value
    *
    /**
    int value() const;
    */
	/**
	

    
    *
    * Determina se � poss�vel a pe�a se mover para determinado quadrado
    * @param quadrado o quadrado destino
    */
    * @return se o movimento � v�lido
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
}; // Cavalo
#endif

