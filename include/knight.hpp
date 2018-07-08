#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "square.hpp"
#include "piece.hpp"

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
    bool canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const;
    
   
   
    /**
     * Mostra a peça
     */
    void display() const;
    
    
    /**
     * Define o código da peça
     */
    void getCodeSymbol();
    

}; // Cavalo

#endif
