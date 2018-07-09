#ifndef RESTRICTED_H
#define RESTRICTED_H

#include "piece.hpp"

class Player;

using namespace std;

class RestrictedPiece : public Piece
{
 public:
    
    /**
    * Cria uma peça que não se mexeu
    *
    * @param cor a cor da peça
    */
    RestrictedPiece(bool isWhite);
    
    
    
    /**
     * Default destructor
     */
    virtual ~RestrictedPiece();

    
	
	/**
    * Move a peça para outro quadrado
    *
    * @return movimento feito
    */
    
	
	virtual bool moveTo(Player& byPlayer, Square& to);

    /**
    * Recebe se a peça já se moveu
    *
    * @return se moveu
    */
    bool hasMoved() const;

 
 private:
   
    // private attributes
    bool _moved;

}; // RestrictedPiece

#endif
