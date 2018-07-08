#include "engine.hpp"


Engine::Engine()
{
}

Engine::~Engine()
{
}
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

uint8_t Engine::new_game()
{
  this->player1.reset( new Player( true ) );
  this->player2.reset( new Player( false ) );
  this->nextPlayer = player2;

  const char initial_game_code_table[8][8] = 
  {
    { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    { }, //These will be filled with 0
    { },
    { },
    { },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
  };
  
  return this->readCodeTable( initial_game_code_table );
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

  PKing   black_king( new King( false ) );
  PQueen  black_queen( new Queen( false ) );
  PBishop black_bishop( new Bishop( false ) );
  PKnight black_knight( new Knight( false ) );
  PRook   black_rook( new Rook( false ) );
  PPawn   black_pawn( new Pawn( false ) );

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

 PCodeTable Engine::returnCodeTable()
 { 
  PCodeTable  code_table;
  uint8_t size = 8;

  PKing   piece_king;
  PQueen  piece_queen;
  PBishop piece_bishop;
  PKnight piece_knight;
  PRook   piece_rook;
  PPawn   piece_pawn;

  code_table = make_unique< unique_ptr<char[]>[] >(size);
    {
      for ( int i = 0; i < size; ++i)
       {
         code_table[i] = make_unique< char[] >(size);

         for (int j = 0; j < size; ++j)
            code_table[i][j] = 0;
       }
    }

  for( uint8_t i = 0; i < 8; i++ )
    {
      for( uint8_t j = 0; j < 8; j++ )
      {
        if( Board::getBoard()->getSquareAt( i, j )->isOccupied() )
        {
         code_table[j][i] = Board::getBoard()->getPieceAt( i, j )->getCodeSymbol();
        }
      } // for( uint8_t j = 0; j < 8; j++ )
    } // for( uint8_t i = 0; i < 8; i++ )

   return code_table;
 } // PCodeTable Engine::returnCodeTable()


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

PPlayer Engine::getNextPlayer()
{
    nextPlayer = opponentOf( nextPlayer );
    return nextPlayer;
}
    
PPlayer Engine::opponentOf( PPlayer player)
{
    PPlayer opponent;
    
    if( player->isWhite() == player1->isWhite() )
    {
        opponent = player2;
    }
    else 
    {
        opponent = player1;
    }

    return opponent;
}