#include <string>
#include "piece.hpp"
#include "player.hpp"

/// Assertiva de entrada da fun��o: if(isWhite)
Piece::Piece(bool isWhite) : _isWhite(isWhite), _square(NULL)
{
    if(isWhite) /// Assertiva de entrada que checa se a pe�a � branca
        _color = "W";
    else
        _color = "B";
        /// Assertiva de sa�da: Se "isWhite" for verdadeiro, a assertiva garante q a pe�a ser� considerada branca
}

Piece::~Piece()
{
}


bool Piece::isWhite() const
{
    return _isWhite;
}

string Piece::color() const
{
    return _color;
}

bool Piece::isOnSquare() const
{
    return _square;
}

Square* Piece::location() const
{
    return _square;
}
