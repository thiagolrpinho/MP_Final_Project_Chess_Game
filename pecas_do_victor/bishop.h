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
    bool canMoveTo(Square& location) const;
    
   
   
    /**
     * Mostra a peça
     */
    void display() const;
    
	
	/**
     * Define o código da peça
     */
    void setCodeSymbol();

}; // Bispo

#endif
