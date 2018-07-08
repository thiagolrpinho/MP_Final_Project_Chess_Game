#include "player.hpp"

Player::Player(bool isWhite, King& myKing, set<Piece*>& myPieces) :
_isWhite(isWhite), _myPieces(myPieces), _myKing(myKing)
{
}

Player::~Player()
{
}