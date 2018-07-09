#ifndef KING_H
#define KING_H

#include <iostream>
#include "restrictedPiece.hpp"

using namespace std;

class King : public RestrictedPiece
{
 public:

   /**
    * Cria um Rei
    *
    * @param cor a cor da pe�a
    */
    King(bool isWhite);
    
    
    
    /**
     * Default destructor
     */
    ~King();

    
	
	/**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;



    /**
    * Determina se o rei pode se mover para um dado quadrado
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
    
    
    /**
     * Define o c�digo da pe�a
     */
    void getCodeSymbol();

}; // Rei

#endif
