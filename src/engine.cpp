#include "engine.hpp"

//! Receives a code table and changes Board according to it if it's valid
  /*!
    \param A valid already allocated char matrix 
    of size_of_table_ dimensions. 
    \return Return a Success(Integer 1) if valid
    or Error(Integer 0) if invalid and no changes are made.
  */
uint8_t Engine::readCodeTable( const char (&array)[8][8] )
{   
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
      if ( isValidCodeSymbol( array[vertical][horizontal] ) == Error )
        return Error;
    }
  }

  for( size_t horizontal = 0; horizontal < 8; horizontal++ )
  {
    for( size_t vertical = 0; vertical < 8; vertical++ )
    {
      if( createPieceAt( horizontal, vertical, array[vertical][horizontal] ) == Error )
        return Error;
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


uint8_t Engine::createPieceAt( uint8_t horizontal_coordinate, 
                uint8_t vertical_coordinate , char code_symbol )
{
  PKing   white_king( new King() );
  PQueen  white_queen( new Queen() );
  PBishop white_bishop( new Bishop() );
  PKnight white_knight( new Knight() );
  PRook   white_rook( new Rook() );
  PPawn   white_pawn( new Pawn() );

  PKing   black_king( new King() );
  PQueen  black_queen( new Queen() );
  PBishop black_bishop( new Bishop() );
  PKnight black_knight( new Knight() );
  PRook   black_rook( new Rook() );
  PPawn   black_pawn( new Pawn() );

  black_king->setBlack();
  black_queen->setBlack();
  black_bishop->setBlack();
  black_knight->setBlack();
  black_rook->setBlack();
  black_pawn->setBlack();

  switch( code_symbol )
      {
        case 0:
        break;
        case 'p':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  white_pawn ) == Error )
          return Error;
        break;
        case 'P':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  black_pawn ) == Error )
          return Error;
        break;
        case 't':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  white_rook ) == Error )
          return Error;
        break;
        case 'T':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  black_rook ) == Error )
          return Error;
        break;
        case 'c':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  white_knight ) == Error )
          return Error;
        break;
        case 'C':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  black_knight ) == Error )
          return Error;
        break;
        case 'b':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  white_bishop ) == Error )
          return Error;
        break;
        case 'B':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  black_bishop ) == Error )
          return Error;
        break;
        case 'r':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  white_queen ) == Error )
          return Error;
        break;
        case 'R':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  black_queen ) == Error )
          return Error;
        break;
        case 'z':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  white_king ) == Error )
          return Error;
        break;
        case 'Z':
          if( Board::getBoard()->setPieceAt( horizontal_coordinate,  vertical_coordinate,  black_king ) == Error )
          return Error;
        break;
      }

  return Success;
}

 unique_ptr<unique_ptr<char[]>[]> Engine::returnCodeTable()
 { 
  unique_ptr<unique_ptr<char[]>[]>  code_table;
  uint8_t size = 8;

  code_table = make_unique< unique_ptr<char[]>[] >(size);
    {
      for ( int i = 0; i < size; ++i)
       {
         code_table[i] = make_unique< char[] >(size);

         for (int j = 0; j < size; ++j)
            code_table[i][j] = j;
       }
    }

  for( uint8_t i = 0; i < 8; i++ )
    {
      for( uint8_t j = 0; j < 8; j++ )
      {
        code_table[i][j] = 0;
      }
    }

   return code_table;
 }


void Engine::printCodeTable( const char (&array)[8][8] )
{
    cout << __func__ << endl;
  for (size_t i = 0; i < 8; ++i)
  {
    cout << i << ": ";
    for (size_t j = 0; j < 8; ++j)
        cout << array[i][j] << '\t';
    cout << endl;
  }
}