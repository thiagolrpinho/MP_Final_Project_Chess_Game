#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _delegate(NULL)
{
}

Pawn::~Pawn()
{
    if(_delegate)
        delete _delegate;
}


void Pawn::setLocation(Square* location)
{
    Piece::setLocation(location);
}


int Pawn::value() const
{
    return 1;
}



///Assertiva de entrada da fun��o: if(!hasMoved() && translationY == 2 && translationX == 0 && Board::getBoard()->isClearVertical(*(this->location()), location))
bool Pawn::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate) const
{
    uint8_t horizontal_absolute_translation, vertical_absolute_translation;
    bool validMove = false;
    
    if( future_horizontal_coordinate >= size_of_table_ ) return move_is_valid;
    if( future_vertical_coordinate >= size_of_table_ ) return move_is_valid;

    horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
    vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );
    
    // andar para frente significa andar para atras do ponto de vista das pe�as pretas
    if(!isWhite())
    {
        translationX *= -1;
        translationY *= -1;
    }
    
    /// o movimento � v�lido se ele for um movimento de um quadrado pra frente(se n�o tiver nenhuma pe�a na frente)
    if( !( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->occupied() )
                                 && vertical_absolute_translation == 1 && horizontal_absolute_translation == 0 )
    {
        validMove = true;
    }
    
    ///  se o pe�o n tiver se movido no jogo e os dois quadrados a sua frente estiverem livres, o pe�o poder� fazer seu movimento especial de se mover 2 quadrados para frente
    /// Assertiva de entrada que checa se o pe�o j� se moveu no jogo
    
    /// o movimento tamb�m � v�lido se o pe�o for comer uma pe�a na diagonal
    else if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->occupied()
             && vertical_absolute_translation == 1 && ( horizontal_absolute_translation == 1
             || horizontal_absolute_translation == -1) )
    {
        validMove = true;
    }        

    return validMove;
}

void Pawn::display() const
{
    if(_delegate)
    {
        _delegate->display();
    }
    else
    {
        cout << _color + "P";
    }
}


char Pawn::getCodeSymbol()
{
  if ( isWhite )
  {
    return'p';

  } else {
    return 'P';
  }
  
}
