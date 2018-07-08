#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class Knight : public Piece
{
 public:
    
    /**
    * Cria um cavalo
    *
    * @param cor a cor da peça
    */
    Knight(bool isWhite);
    
   
   
    /**
     * Default destructor
     */
    ~Knight();

   
   
    /**
    * Pega valor da peça
    *
    * @return the value
    */
    int value() const;

    
	
	/**
    * Determina se é possível a peça se mover para determinado quadrado
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
    
    
    /**
     * Define o código da peça
     */
    void setCodeSymbol();

}; // Cavalo

#endif
