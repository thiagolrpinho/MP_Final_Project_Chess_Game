#include "queen.hpp"
#include "board.hpp"

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}

Queen::Queen()
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
               uint8_t future_vertical_coordinate ) const
{
    bool move_is_valid = false;
    uint8_t horizontal_absolute_translation, vertical_absolute_translation;
    bool horizontal_direction_positive = actual_horizontal_coordinate < future_horizontal_coordinate;
    bool vertical_direction_positive = actual_vertical_coordinate < future_vertical_coordinate;
    uint8_t horizontal_capture_piece_coordinate;
    uint8_t vertical_capture_piece_coordinate;
    uint8_t vertical_direction, horizontal_direction;

  horizontal_absolute_translation = abs( actual_horizontal_coordinate - future_horizontal_coordinate );
  vertical_absolute_translation =  abs( actual_vertical_coordinate - future_vertical_coordinate);

  if( horizontal_direction_positive )
  {
    horizontal_direction = -1;
  } else {
    horizontal_direction = 1;
  }

  if( vertical_direction_positive )
  {
    vertical_direction = -1;
  } else {
    vertical_direction = 1;
  }
  if( horizontal_absolute_translation == 1 ) horizontal_direction = 0;
  if( vertical_absolute_translation == 1  ) vertical_direction = 0;

  horizontal_capture_piece_coordinate = future_horizontal_coordinate + horizontal_direction;
  vertical_capture_piece_coordinate = future_vertical_coordinate + vertical_direction;

  if( horizontal_absolute_translation == 1 && vertical_absolute_translation == 1  )
  { 
    if( !Board::getBoard()->isClearDiagonal(  actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_horizontal_coordinate,
                future_vertical_coordinate ) )
    { 
      if( Board::getBoard()->getPieceAt( future_horizontal_coordinate,
                            future_vertical_coordinate )->isWhite == this->isWhite )
      {
        return false;
      } else {
        return true;
      }
    } else {
      return true;
    }

  } else if( Board::getBoard()->isClearDiagonal(  actual_horizontal_coordinate,
                actual_vertical_coordinate,  horizontal_capture_piece_coordinate,
                vertical_capture_piece_coordinate ) )
  { 
    if( !Board::getBoard()->isClearDiagonal(  actual_horizontal_coordinate,
                actual_vertical_coordinate,  future_horizontal_coordinate,
                future_vertical_coordinate ) )
    {
      if( Board::getBoard()->getPieceAt( future_horizontal_coordinate,
                            future_vertical_coordinate )->isWhite == this->isWhite )
      {
          return false;
      } else {
          return true;
      }
    } else {
      return true;
    }
  }

  if( vertical_absolute_translation == 1 )
  {
    if( !Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
            actual_vertical_coordinate,  future_vertical_coordinate ) )
    {   
      if( Board::getBoard()->getPieceAt( actual_horizontal_coordinate,
                            future_vertical_coordinate )->isWhite == this->isWhite )
      {
          return false;
      } else {
          return true;
      }
    } else {
        return true;
      }

  } else if( Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
              actual_vertical_coordinate,  vertical_capture_piece_coordinate ) )
  {
    if( !Board::getBoard()->isClearVertical( actual_horizontal_coordinate,
            actual_vertical_coordinate,  future_vertical_coordinate ) )
    {   
      if( Board::getBoard()->getPieceAt( actual_horizontal_coordinate,
                            future_vertical_coordinate )->isWhite == this->isWhite )
      {
          return false;
      } else {
          return true;
      }
    } else {
        return true;
      }
  /// Assertiva de entrada que checa se o movimento da torre � v�lido
  /// o movimento � v�lido se a torre tiver se movendo em uma reta horizontal
  } else if( horizontal_absolute_translation == 1 ) 
  {
    if( !Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
              actual_vertical_coordinate,  future_horizontal_coordinate ) )
      {
          if( Board::getBoard()->getPieceAt(future_horizontal_coordinate,
                            actual_vertical_coordinate )->isWhite == this->isWhite )
          {
              return false;
          } else {
              return true;
          }

      } else {
        move_is_valid = true;
      }
  } else if( Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
              actual_vertical_coordinate,  horizontal_capture_piece_coordinate ))
  {
      if( !Board::getBoard()->isClearHorizontal( actual_horizontal_coordinate,
              actual_vertical_coordinate,  future_horizontal_coordinate ) )
      {
          if( Board::getBoard()->getPieceAt(future_horizontal_coordinate,
                            actual_vertical_coordinate )->isWhite == this->isWhite )
          {
              return false;
          } else {
              return true;
          }

      } else {
        move_is_valid = true;
      }
  }

    return move_is_valid;
}


char Queen::getCodeSymbol() const
{
  if ( isWhite )
  {
    return 'r';

  } else {
    return 'R';
  }
}
