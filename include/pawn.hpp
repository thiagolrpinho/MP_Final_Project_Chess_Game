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
    * Cria um peão
    *
    * @param cor a cor da peça
    */
    Pawn(bool isWhite);
    
    /**
     * Default destructor
     */
    ~Pawn();

    /**
    * Seta qual quadrado a peça está localizada
    *
    * @param local do quadrado
    */
    void setLocation(Square* location);

    /**
    * Pega o valor da peça
    *
    * @return o valor
    */
    int value() const;
    
    /**
     * Move a peça para outro quadrado
     *
     * @return o movimento feito
     */
    bool moveTo(Player& byPlayer, Square& to);

    /**
    * Determina se a peça pode se mover para o quadrado recebido baseado na geometria do movimento
    *
    * @param quadrado o quadrado destino
    * @return se o movimento é válido
    */
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;

    /**
    * Mostra a peça
    */
    void display() const;
    
   
    void getCodeSymbol();
  
 private:

    // Private attributes
    Piece* _delegate;

 // Peão
};
#endif
