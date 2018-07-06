#include "engine.hpp"

//! Receives a code table and changes Board according to it if it's valid
  /*!
    \param A valid already allocated char matrix 
    of size_of_table_ dimensions. 
    \return Return a Success(Integer 1) if valid
    or Error(Integer 0) if invalid and no changes are made.
  */
uint8_t Engine::readCodeTable( char (&array)[8][8] )
{   
  PPiece a_piece( new Piece() );

  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      switch( array[horizontal][vertical] )
      {
        case 0:
        break;
        case 'p':
        break;
        case 'P':
        break;
        case 't':
        break;
        case 'T':
        break;
        case 'c':
        break;
        case 'C':
        break;
        case 'b':
        break;
        case 'B':
        break;
        case 'r':
        break;
        case 'R':
        break;
        case 'z':
        break;
        case 'Z':
        break;

        default:
          return Error;
        break;
      }
    }
  }

  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      if( Board::getBoard()->setPieceAt( horizontal, vertical, a_piece ) == Error )
      return Error;
    }
  }
  return Success;
}

void Engine::printCodeTable( char (&array)[8][8] )
{
    std::cout << __func__ << std::endl;
  for (size_t i = 0; i < 8; ++i)
  {
    std::cout << i << ": ";
    for (size_t j = 0; j < 8; ++j)
        std::cout << array[i][j] << '\t';
    std::cout << std::endl;
  }
}