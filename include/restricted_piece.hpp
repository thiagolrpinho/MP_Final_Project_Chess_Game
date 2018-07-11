#ifndef RESTRICTED_HPP
#define RESTRICTED_HPP

#include "piece.hpp"

class RestrictedPiece: public Piece 
{
 public:
    
    /**
    * Cria uma pe�a que n�o se mexeu
    *
    * @param cor a cor da pe�a
    */
    RestrictedPiece(bool isWhite);
    
    RestrictedPiece();
    
    /**
     * Default destructor
     */
    virtual ~RestrictedPiece();

    
	
    virtual bool canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const = 0;
    /**
    * Recebe se a pe�a j� se moveu
    *
    * @return se moveu
    */
    bool hasMoved() const;

    void setMoved() const
    {
        _moved = true;
    };
 
 private:
   
    mutable bool _moved;
    // private attributes

}; // RestrictedPiece

#endif
