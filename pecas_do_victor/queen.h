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
    * @param cor a cor da peça
    */
    Queen(bool isWhite);
    
    
	
	/**
     * Default destructor
     */
    ~Queen();

    
	
	/**
    * Pega o valor da peça
    *
    * @return o valor
    */
    int value() const;

    
	
	/**
    * Determina se a peça pode se mover para um dado quadrado
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

}; // Rainha

#endif
