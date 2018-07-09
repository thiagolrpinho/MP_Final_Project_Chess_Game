#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "square.hpp"
#include "piece.hpp"

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
    
	
	bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
    
    /**
     * Mostra a peça
     */
    void display() const;
    
    
    /**
     * Define o código da peça
     */
    void getCodeSymbol();

}; // Rainha

#endif
