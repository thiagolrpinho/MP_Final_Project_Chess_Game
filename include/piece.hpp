#ifndef CATCH_H
#define CATCH_H
#include "catch.hpp"
#endif

#ifndef PIECE_HPP
#define PIECE_HPP
#include <string>
#include "player.hpp"

class Piece 
{ 

  public:
  bool isWhite = true;

  Piece();
  Piece( char is_being_created_white );
  
  void setBlack();
  virtual char  getCodeSymbol() const = 0;
    /**
     * Default destructor
    virtual ~Piece();
     */
   
    /**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    virtual int value() const = 0;


    /**
    * Determina se a pe�a pode se mover para um dado quadrado baseado na geometria do movimento
    *
    * @param quadrado o quadrado destino
    * @return se o movimento � v�lido
    */
    virtual bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const = 0;

}; // Pe�a

#endif
