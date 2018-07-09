#include "player.h"
#include "restrictedPiece.h"

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite)
{
    _moved = false;
}
    
    
    
RestrictedPiece::~RestrictedPiece()
{
}



/// Assertiva de entrada da função: if(validMove && !_moved)
bool RestrictedPiece::moveTo(Player& byPlayer, Square& to)
{
    bool validMove = Piece::moveTo(byPlayer, to);
    
    /// Assertiva de entrada que checa se a peça já se moveu no jogo
    /// "_moved" só é trocado quando um movimento válido é feito e a peça ainda não se moveu no jogo
    if(validMove && !_moved)
    {
        _moved = true;
    }
    
    /// Assertiva de saída: é garantido que o jogo irá considerar a peça movida como "já movida"
    return validMove;
}



bool RestrictedPiece::hasMoved() const
{
    return _moved;
}
