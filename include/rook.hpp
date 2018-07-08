#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "restrictedPiece.hpp"
#include "square.hpp"

using namespace std;

class Rook : public RestrictedPiece
{
 public:
    
    /**
    * Cria uma torre
    *
    * @param cor a cor da pe�a
    */
    Rook(bool isWhite);
    
   
   
    /**
     * Default destructor
     */
    ~Rook();

    
	
	/**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;

    
	
	/**
    * Determina se pe�a pode se mover pra um dado quadrado
    *
    * @param quadrado o quadrado destino
    * @return se o movimento � legal
    */
    bool canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const;
    
   
   
    /**
     * Mostra a pe�a
     */
    void display() const;
    
    
    /**
     * Define o c�digo da pe�a
     */
    void getCodeSymbol();

}; // Torre

#endif
