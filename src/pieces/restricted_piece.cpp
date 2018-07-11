#include "restricted_piece.hpp"

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite)
{
    _moved = false;
}

RestrictedPiece::RestrictedPiece()
{   
    isWhite = true;
    _moved = false;
}
    
    
RestrictedPiece::~RestrictedPiece()
{
}





bool RestrictedPiece::hasMoved() const
{
    return _moved;
}
