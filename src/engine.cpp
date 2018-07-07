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
  PKing white_king( new King() );
  PQueen  white_queen( new Queen() );
  PBishop white_bishop( new Bishop() );
  PKnight white_knight( new Knight() );
  PRook   white_rook( new Rook() );
  PPawn   white_pawn( new Pawn() );

  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      if ( isValidCodeSymbol( array[horizontal][vertical] ) == Error )
        return Error;
    }
  }

  for( size_t horizontal = 0; horizontal < 8; horizontal++ )
  {
    for( size_t vertical = 0; vertical < 8; vertical++ )
    {
      switch( array[horizontal][vertical] )
      {
        case 0:
        break;
        case 'p':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_pawn ) == Error )
          return Error;
        break;
        case 'P':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_pawn ) == Error )
          return Error;
        break;
        case 't':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_rook ) == Error )
          return Error;
        break;
        case 'T':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_rook ) == Error )
          return Error;
        break;
        case 'c':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_knight ) == Error )
          return Error;
        break;
        case 'C':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_knight ) == Error )
          return Error;
        break;
        case 'b':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_bishop ) == Error )
          return Error;
        break;
        case 'B':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_bishop ) == Error )
          return Error;
        break;
        case 'r':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_queen ) == Error )
          return Error;
        break;
        case 'R':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_queen ) == Error )
          return Error;
        break;
        case 'z':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_king ) == Error )
          return Error;
        break;
        case 'Z':
          if( Board::getBoard()->setPieceAt( horizontal, vertical, white_king ) == Error )
          return Error;
        break;
      }
    }
  }
  return Success;
}

uint8_t Engine::isValidCodeSymbol( char code_symbol )
{
  switch( code_symbol )
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