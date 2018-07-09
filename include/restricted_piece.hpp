#ifndef RESTRICTED_HPP
#define RESTRICTED_HPP

#include "piece.hpp"

class RestrictedPiece : public Piece
{
 public:
    
    /**
    * Cria uma pe�a que n�o se mexeu
    *
    * @param cor a cor da pe�a
    */
    RestrictedPiece(bool isWhite);
    
    
    
    /**
     * Default destructor
     */
    virtual ~RestrictedPiece();

    
	
	/**
    * Move a pe�a para outro quadrado
    *
    * @return movimento feito
    */
    
    /**
    * Recebe se a pe�a j� se moveu
    *
    * @return se moveu
    */
    bool hasMoved() const;

 
 private:
   
    // private attributes
    bool _moved;

}; // RestrictedPiece

#endif
