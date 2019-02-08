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
  Board::getBoard()->cleanBoard();

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

uint8_t Engine::isValidEditedTable( const char (&array)[8][8] )
{
  // function receiveis an array of chars that represents a chess board
  // and returns Success if it's a valid chess board or
  // Error if not
  
  // White pieces counters
  uint8_t white_pawn = 0;
  uint8_t white_rook = 0;
  uint8_t white_knight = 0;
  uint8_t white_bishop = 0;
  uint8_t white_queen = 0;
  uint8_t white_king = 0;

  // Black pieces counters
  uint8_t black_pawn = 0;
  uint8_t black_rook = 0;
  uint8_t black_knight = 0;
  uint8_t black_bishop = 0;
  uint8_t black_queen = 0;
  uint8_t black_king = 0;

  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      // If any symbol read is not a valid board chess code
      // then it returns an Error
      if ( isValidCodeSymbol( array[vertical][horizontal] ) == Error )
        return Error;
      switch( array[vertical][horizontal] )
      {
        case 'p':
          white_pawn++;
        break;
        case 'P':
          black_pawn++;
        break;
        case 't':
          white_rook++;
        break;
        case 'T':
          black_rook++;
        break;
        case 'c':
          white_knight++;
        break;
        case 'C':
          black_knight++;
        break;
        case 'b':
          white_bishop++;
        break;
        case 'B':
          black_bishop++;
        break;
        case 'r':
          white_queen++;
        break;
        case 'R':
          black_queen++;
        break;
        case 'z':
          white_king++;
        break;
        case 'Z':
          black_king++;
        break;

        default:
        break;
      }
    }
  }

  // White pieces check
  if( white_king != 1 )   return Error;
  if( white_queen > 1 )   return Error;
  if( white_rook > 2 )    return Error;
  if( white_bishop > 2 )  return Error;
  if( white_knight > 2 )  return Error;
  if( white_pawn > 8)     return Error;
  
  // Black pieces check
  if( black_king != 1 )   return Error;
  if( black_queen > 1 )   return Error;
  if( black_rook > 2 )    return Error;
  if( black_bishop > 2 )  return Error;
  if( black_knight > 2 )  return Error;
  if( black_pawn > 8 )    return Error;

  return Success;
}

uint8_t Engine::isValidCodeSymbol( char code_symbol )
{
  // Valid code symbols used are
  // p for pawn
  // t for rook
  // c for knight
  // r for queen
  // z for king
  // High case pieces are black and low cases are white
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
          if ( vertical_coordinate != 1 && vertical_coordinate != (8 - 2) ) white_pawn->setMoved();
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

  /* Method receives a code table array[8][8]
      and returns true if the moviment is valid or false if not
  */
bool Engine::isValidMove( const char (&new_code_table)[8][8]  )
{
  PCodeTable actual_game_code_table;
  uint8_t number_of_different_symbols = 0; //If there are no differences, then it's the same board.
  uint8_t first_difference_horizontal_coordinate;
  uint8_t first_difference_vertical_coordinate;
  uint8_t second_difference_horizontal_coordinate;
  uint8_t second_difference_vertical_coordinate;
  bool first_difference_is_origin, first_was_occupied, second_was_occupied;
  bool first_is_occupied, second_is_occupied;

  // Validates if the codes are valid symbols
  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      if ( isValidCodeSymbol( new_code_table[vertical][horizontal] ) == Error )
        return false;
    }
  }
  actual_game_code_table = returnCodeTable();

  // Verifies the number of pieces different from the last game state
  // then stores the coordinates of the different changes
  for( size_t horizontal = 0; horizontal < 8; ++horizontal )
  {
    for( size_t vertical = 0; vertical < 8; ++vertical )
    {
      if ( new_code_table[vertical][horizontal]  != actual_game_code_table[vertical][horizontal] )
      {
        switch( ++number_of_different_symbols )
        {
          case 1:
            first_difference_horizontal_coordinate = (uint8_t)horizontal;
            first_difference_vertical_coordinate = (uint8_t)vertical;
            first_is_occupied = new_code_table[vertical][horizontal] == 0;
          break;
          case 2:
            second_difference_horizontal_coordinate = (uint8_t)horizontal;
            second_difference_vertical_coordinate = (uint8_t)vertical;
            second_is_occupied = new_code_table[vertical][horizontal] == 0;
          break;
          default:
          break;
        }
      }
    }
  }

  if( number_of_different_symbols == 0 ) return true; // If nothing change, then it's valid
  if( number_of_different_symbols != 2 ) return false; // If the movement changed more than two symbols, it's invalid

  first_was_occupied = Board::getBoard()->getSquareAt( first_difference_horizontal_coordinate,
                                 first_difference_vertical_coordinate)->isOccupied();

  second_was_occupied = Board::getBoard()->getSquareAt( second_difference_horizontal_coordinate, 
                                second_difference_vertical_coordinate)->isOccupied(); 
 
  if ( first_was_occupied && second_was_occupied )
  {
    if ( first_is_occupied )
    {
      first_difference_is_origin = false;
    } else if ( second_is_occupied ) {
      first_difference_is_origin = true;
    } else {
      return false;
    }
  } else if( first_was_occupied ) {
    first_difference_is_origin = true;

  } else if( second_was_occupied ) {
    first_difference_is_origin = false;

  } else {
    return false; //If no pieces were on the given differences, there can not be two new pieces.
  }

  // Then search the origin of the movement and validates if that was a valid move
  if( first_difference_is_origin )
  {
    if( Board::getBoard()->getPieceAt( first_difference_horizontal_coordinate,
             first_difference_vertical_coordinate )->canMoveTo( first_difference_horizontal_coordinate,
             first_difference_vertical_coordinate, second_difference_horizontal_coordinate,
             second_difference_vertical_coordinate ) == false ) return false;
  } else {
    if( Board::getBoard()->getPieceAt( second_difference_horizontal_coordinate,
             second_difference_vertical_coordinate )->canMoveTo( second_difference_horizontal_coordinate,
             second_difference_vertical_coordinate, first_difference_horizontal_coordinate,
             first_difference_vertical_coordinate ) == false ) return false;
  }

  return true;
} // bool Engine::isValidMove( const char (&new_code_table)[8][8]  )

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


shared_ptr<Engine> Engine::getEngine()
{
//If there's no board, then create one.
    if( an_engine_ == nullptr )
    {  
        try {
            an_engine_.reset( new Engine() );
            //Reset board table to new board
        } catch ( int throwned_error) {
            // If there was a failure creating board
            throw Error;
        }
    }

    return an_engine_;
}

shared_ptr<Engine> Engine::an_engine_ = nullptr;