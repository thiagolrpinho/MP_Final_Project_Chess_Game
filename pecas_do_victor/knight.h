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
    * @param cor a cor da pe�a
    */
    Knight(bool isWhite);
    
   
   
    /**
     * Default destructor
     */
    ~Knight();

   
   
    /**
    * Pega valor da pe�a
    *
    * @return the value
    */
    int value() const;

    
	
	/**
    * Determina se � poss�vel a pe�a se mover para determinado quadrado
    *
    * @param quadrado o quadrado destino
    * @return se o movimento � v�lido
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
    
    
    /**
     * Define o c�digo da pe�a
     */
    char setCodeSymbol();

}; // Cavalo

#endif
