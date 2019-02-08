#include "pawn.hpp"
#include "queen.hpp"
#include "board.hpp"
#include "square.hpp"

Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _delegate(NULL)
{
}

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}



int Pawn::value() const
{
    return 1;
}



///Assertiva de entrada da fun��o: if(!hasMoved() && vertical_absolute_translantion == 2 && horizontal_absolute_translation == 0 && Board::getBoard()->isClearVertical(*(this->location()), location))
bool Pawn::canMoveTo( uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
    uint8_t horizontal_absolute_translation, vertical_absolute_translation;
    int8_t vertical_direction, horizontal_direction;
    bool validMove = false;
    
    horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
    vertical_absolute_translation = abs( actual_vertical_coordinate - future_vertical_coordinate );
    
    // andar para frente significa andar para atras do ponto de vista das pe�as pretas
    if(!isWhite )
    {
        vertical_direction = -1;
    } else {
        vertical_direction = 1;
    }
    
    /// o movimento � v�lido se ele for um movimento de um quadrado pra frente(se n�o tiver nenhuma pe�a na frente)
    if( !( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied() )
                                 && vertical_absolute_translation == 1 && horizontal_absolute_translation == 0 )
    {
        validMove = true;
        if(!hasMoved()) setMoved();

    }
    
    ///  se o pe�o n tiver se movido no jogo e os dois quadrados a sua frente estiverem livres, o pe�o poder� fazer seu movimento especial de se mover 2 quadrados para frente
    /// Assertiva de entrada que checa se o pe�o j� se moveu no jogo
    else if( !hasMoved() && vertical_absolute_translation == 2 && horizontal_absolute_translation == 0 &&
            Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
             actual_vertical_coordinate, future_vertical_coordinate ) )
    {
        validMove = true;
        setMoved();
    }

    /// o movimento tamb�m � v�lido se o pe�o for comer uma pe�a na diagonal
    else if( isWhite ) // Se for branca
    {
        if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied()
                && vertical_direction == 1  )
        {
            validMove = true;
        }
    } else  // Se a peça for preta
    {
        if( Board::getBoard()->getSquareAt( future_horizontal_coordinate, future_vertical_coordinate )->isOccupied()
             && vertical_direction == -1 )
        {
            validMove = true;
        }
    }       

    return validMove;
}

char Pawn::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'p';

  } else {
    return 'P';
  }
  
}
