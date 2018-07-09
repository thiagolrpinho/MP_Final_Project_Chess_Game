#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "square.hpp"
#include "restrictedPiece.hpp"

using namespace std;

class Pawn : public RestrictedPiece
{
 public:
    
    /**
    * Cria um pe�o
    *
    * @param cor a cor da pe�a
    */
    Pawn(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Pawn();

    /**
    * Seta qual quadrado a pe�a est� localizada
    *
    * @param local do quadrado
    */
    void setLocation(Square* location);

    /**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;
    
    /**
     * Move a pe�a para outro quadrado
     *
     * @return o movimento feito
     */
    bool moveTo(Player& byPlayer, Square& to);

    /**
    * Determina se a pe�a pode se mover para o quadrado recebido baseado na geometria do movimento
    *
    * @param quadrado o quadrado destino
    * @return se o movimento � v�lido
    */
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;

    /**
    * Mostra a pe�a
    */
    void display() const;
    
   
    void getCodeSymbol();
  
 private:

    // Private attributes
    Piece* _delegate;

 // Pe�o
};
#endif
