#include "bishop.hpp"

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
}

Bishop::~Bishop()
{
}

int Bishop::value() const
{
    return 3;
}

///Assertivas de entrada: if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
bool Bishop::canMoveTo(uint8_t horizontal_coordinate, uint8_t vertical_coordinate) const
{
    bool validMove = false;
    
    if(Board::getBoard()->isClearDiagonal(*(this->location()), location))///Assertivas de entrada que checa se o movimento est� sendo na diagonal
    {
        validMove = true;
   /// Assertiva de sa�da:Se a assertiva de entrada (Board::getBoard()->isClearDiagonal(*(this->location()), location)) for verdadeira, o programa ir� garantir que a pe�a est� se movimentando na diagonal
    }
    
    return validMove;
}

void Bishop::display() const
{
    cout << _color + "B";
}


void Bishop::setCodeSymbol()
{
  if ( isWhite() )
  {
    code_symbol_= 'b';

  } else {
    code_symbol_ = 'B';
  }
  
}
