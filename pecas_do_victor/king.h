#ifndef KING_H
#define KING_H

#include <iostream>
#include "restrictedPiece.h"

using namespace std;

class King : public RestrictedPiece
{
 public:

   /**
    * Cria um Rei
    *
    * @param cor a cor da peça
    */
    King(bool isWhite);
    
    
    
    /**
     * Default destructor
     */
    ~King();

    
	
	/**
    * Pega o valor da peça
    *
    * @return o valor
    */
    int value() const;



    /**
    * Determina se o rei pode se mover para um dado quadrado
    *
    * @param quadrado o quadrado destino
    * @return se o movimento é válido
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

}; // Rei

#endif
