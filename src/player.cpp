Player::Player(string name, bool isWhite, King& myKing, set<Piece*>& myPieces) :
_name(name), _isWhite(isWhite), _myPieces(myPieces), _myKing(myKing)
{
}

Player::~Player()
{
}