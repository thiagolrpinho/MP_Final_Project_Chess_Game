#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.hpp"

using namespace std;

class Bishop : public Piece
{
 public:
    
    /**
    * Cria um bispo
    *
    * @param cor a cor da peça
    */
    Bishop(bool isWhite);
    
   
   
    /**
     * Default destructor
     */
    ~Bishop();

    
	
	/**
    * Recebe o valor da peça
    *
    * @retorna o valor
    */
    int value() const;

    
	
	/**
    * Checa se a peça pode se mover para um dado quadrado(square).
    *
    * @param o quadrado q peça esta querendo ir
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
    char getCodeSymbol();

}; // Bispo

#endif
