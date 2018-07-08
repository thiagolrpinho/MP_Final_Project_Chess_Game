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
    bool canMoveTo(Square& location) const;
    
   
   
    /**
     * Mostra a peça
     */
    void display() const;
    
    
    /**
     * Define o código da peça
     */
    void setCodeSymbol();

}; // Torre

#endif
