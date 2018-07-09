#include "queen.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}



Queen::~Queen()
{
}



int Queen::value() const
{
    return 9;
}


/// Assertivas de entrada da fun��o: 
///if(Board::getBoard()->isClearVertical(*(this->location()), location)), 
///if(Board::getBoard()->isClearVertical(*(this->location()), location)), 
///else if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
bool Queen::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const
{
    bool validMove = false;
    
    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se a rainha tiver se movendo uma reta vertical
    if(Board::getBoard()->isClearVertical(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se a rainha tiver se movendo uma reta horizontal
    else if(Board::getBoard()->isClearVertical(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de entrada que checa se o movimento � v�lido
    /// movimento � v�lido se a rainha tiver se movendo uma reta diagonal
    else if(Board::getBoard()->isClearDiagonal(*(this->location()), location))
    {
        validMove = true;
    }
    
    /// Assertiva de sa�da: garante que o movimento da rainha � v�lido
    return validMove;
}

void Queen::display() const
{
    cout << _color + "Q";
}


char Queen::getCodeSymbol()
{
  if ( isWhite )
  {
    return'r';

  } else {
    return 'R';
  }
