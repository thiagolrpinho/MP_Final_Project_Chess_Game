#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "restrictedPiece.h"
#include "square.h"

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
    bool canMoveTo(Square& location) const;
    
   
   
    /**
     * Mostra a pe�a
     */
    void display() const;
    
    
    /**
     * Define o c�digo da pe�a
     */
    char setCodeSymbol();

}; // Torre

#endif
