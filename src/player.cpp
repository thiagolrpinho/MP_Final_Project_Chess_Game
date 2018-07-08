#include "player.hpp"

Player::Player(bool isWhite ) :
_isWhite(isWhite)
{
}

Player::~Player()
{
}


bool Player::isWhite() const
{
    return _isWhite;
}

