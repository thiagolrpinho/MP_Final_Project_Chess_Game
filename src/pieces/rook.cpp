#include "rook.hpp"
#include "board.hpp"

Rook::Rook(bool isWhite) : RestrictedPiece(isWhite)
{
}

Rook::Rook()
{
}

Rook::~Rook()
{
}


int Rook::value() const
{
    return 5;
}


/// Assertivas de entrada da fun��o: 
/// if(Board::getBoard()->isClearVertical(*(this->location()), location))
/// if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
 
bool Rook::canMoveTo(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const
{
    bool move_is_valid = false;
    int8_t vertical_direction, horizontal_direction;
    uint8_t horizontal_capture_piece_coordinate;
    uint8_t vertical_capture_piece_coordinate;
    
    
    // andar para frente significa andar para atras do ponto de vista das pe�as pretas
    if( actual_horizontal_coordinate - future_horizontal_coordinate > 0)
    {
        horizontal_direction = -1;
    } else if( actual_horizontal_coordinate - future_horizontal_coordinate < 0) {
        horizontal_direction = 1;
    } else {
        horizontal_direction = 0;
    }

    if( actual_vertical_coordinate - future_vertical_coordinate > 0)
    {
        vertical_direction = -1;
    } else if( actual_vertical_coordinate - future_vertical_coordinate > 0) {
        vertical_direction = 1;
    } else {
        vertical_direction = 0;
    }

    horizontal_capture_piece_coordinate = future_horizontal_coordinate + horizontal_direction;
    vertical_capture_piece_coordinate = future_vertical_coordinate + vertical_direction;
    
    /// Assertiva de entrada que checa se o movimento da torre � v�lido
    /// o movimento � v�lido se a torre tiver se movendo em uma reta vertical
    if( Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
                actual_vertical_coordinate,  vertical_capture_piece_coordinate ))
    {
        if( !Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_vertical_coordinate ) )
        {
            if( Board::getBoard()->getPieceAt(actual_horizontal_coordinate,
                             future_vertical_coordinate )->isWhite == isWhite )
            {
                return false;
            } else {
                return true;
            }

        }
    /// Assertiva de entrada que checa se o movimento da torre � v�lido
    /// o movimento � v�lido se a torre tiver se movendo em uma reta horizontal
    } else if( Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
                actual_vertical_coordinate,  horizontal_capture_piece_coordinate ))
    {
        if( !Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_horizontal_coordinate ) )
        {
            if( Board::getBoard()->getPieceAt(future_horizontal_coordinate,
                             actual_vertical_coordinate )->isWhite == isWhite )
            {
                return false;
            } else {
                return true;
            }

        }
    }
    
    /// Assertiva de sa�da: � garantido que o movimento da torre � v�lido
    return move_is_valid;
}



char Rook::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 't';

  } else {
    return 'T';
  }
  
}
