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
    * @param cor a cor da pe�a
    */
    Bishop(bool isWhite);
    
   
   
    /**
     * Default destructor
     */
    ~Bishop();

    
	
	/**
    * Recebe o valor da pe�a
    *
    * @retorna o valor
    */
    int value() const;

    
	
	/**
    * Checa se a pe�a pode se mover para um dado quadrado(square).
    *
    * @param o quadrado q pe�a esta querendo ir
    * @return se o movimento � v�lido
    */
    bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const;
    
   
   
    /**
     * Mostra a pe�a
     */
    void display() const;
    
	
	/**
     * Define o c�digo da pe�a
     */
    char getCodeSymbol();

}; // Bispo

#endif
