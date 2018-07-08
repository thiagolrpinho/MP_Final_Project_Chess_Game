#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
#include "square.h"

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
    bool canMoveTo(Square& location) const;
    
   
   
    /**
     * Mostra a pe�a
     */
    void display() const;
    
	
	/**
     * Define o c�digo da pe�a
     */
    char setCodeSymbol();

}; // Bispo

#endif
