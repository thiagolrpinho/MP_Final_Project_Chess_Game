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
    * @param cor a cor da peça
    */
    Rook(bool isWhite);
    
   
   
    /**
     * Default destructor
     */
    ~Rook();

    
	
	/**
    * Pega o valor da peça
    *
    * @return o valor
    */
    int value() const;

    
	
	/**
    * Determina se peça pode se mover pra um dado quadrado
    *
    * @param quadrado o quadrado destino
    * @return se o movimento é legal
    */
    bool canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const;
    
   
   
    /**
     * Mostra a peça
     */
    void display() const;
    
    
    /**
     * Define o código da peça
     */
    void getCodeSymbol();

}; // Torre

#endif
