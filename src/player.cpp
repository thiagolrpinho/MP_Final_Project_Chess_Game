#include "player.hpp"

Player::Player(bool isWhite, King& myKing, set<Piece*>& myPieces) :
_isWhite(isWhite), _myPieces(myPieces), _myKing(myKing)
{
}

Player::~Player()
{
}


bool Player::isWhite() const
{
    return _isWhite;
}

set<Piece*>* Player::myPieces() const
{
    return &_myPieces;
}

King* Player::myKing() const
{
    return &_myKing;
}