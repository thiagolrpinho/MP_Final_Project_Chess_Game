#include "player.h"
#include "restrictedPiece.h"

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite)
{
    _moved = false;
}
    
    
    
RestrictedPiece::~RestrictedPiece()
{
}



/// Assertiva de entrada da fun��o: if(validMove && !_moved)
bool RestrictedPiece::moveTo(Player& byPlayer, Square& to)
{
    bool validMove = Piece::moveTo(byPlayer, to);
    
    /// Assertiva de entrada que checa se a pe�a j� se moveu no jogo
    /// "_moved" s� � trocado quando um movimento v�lido � feito e a pe�a ainda n�o se moveu no jogo
    if(validMove && !_moved)
    {
        _moved = true;
    }
    
    /// Assertiva de sa�da: � garantido que o jogo ir� considerar a pe�a movida como "j� movida"
    return validMove;
}



bool RestrictedPiece::hasMoved() const
{
    return _moved;
}
