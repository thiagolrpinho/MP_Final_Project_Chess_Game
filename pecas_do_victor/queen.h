#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class Queen : public Piece
{
 public:
    
    /**
    * Cria uma Rainha
    *
    * @param cor a cor da pe�a
    */
    Queen(bool isWhite);
    
    
	
	/**
     * Default destructor
     */
    ~Queen();

    
	
	/**
    * Pega o valor da pe�a
    *
    * @return o valor
    */
    int value() const;

    
	
	/**
    * Determina se a pe�a pode se mover para um dado quadrado
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

}; // Rainha

#endif
