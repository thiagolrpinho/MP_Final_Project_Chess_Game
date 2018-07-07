#include "engine.hpp"
#include <typeinfo>

typedef shared_ptr<Engine>  PEngine;
typedef shared_ptr<Piece>   PPiece;
typedef shared_ptr<King>    PKing;
typedef shared_ptr<Queen>   PQueen;
typedef shared_ptr<Bishop>  PBishop;
typedef shared_ptr<Knight>  PKnight;
typedef shared_ptr<Rook>    PRook;
typedef shared_ptr<Pawn>    PPawn;

//! These tests will be focused on engine class
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! creates objects within Engine class
  // These tests will focus on:./
  SECTION( "An engine can be successfully created" ) 
  {
    try {
      PEngine valid_engine( new Engine());
      REQUIRE_FALSE( valid_engine == nullptr );  
    } catch (int e) {
      REQUIRE_FALSE( "The Engine cannot be succesfully created." );
    }
  } // SECTION( "An engine can be successfully created" )
} // TEST_CASE( "Create", "[Engine]" )

TEST_CASE( "Read Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! reads objects within Engine class
  // These tests will focus on:./
  PEngine valid_engine( new Engine());
  char initial_game_code_table[8][8] = 
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

  char wrong_game_code_table[8][8] = 
  {
    { 'T', 'C', 'B', 'R', 'Y', 'B', 'C', 'T'},
    { 'P', 'X', 'P', 'P', 'P', 'P', 'P', 'P'},
    { }, //These will be filled with 0
    { },
    { },
    { },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
  };

  char game_with_one_kind_of_piece_code_table[8][8] = 
  {
    { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' }, // Columns coordinates
    { },
    { }, //These will be filled with 0
    { },
    { },
    { },
    { },
    { 0,0,0,0,'z' } //Matrix[5][7] = king
  };

  SECTION( "An engine can be read one char code table and return Success if correct" ) 
  {
      REQUIRE( valid_engine->readCodeTable(initial_game_code_table) == Success );
  } // SECTION( "An engine can be read one char code table and return Error if not correct" )

  SECTION( "An engine can be read one char code table and return Error if not correct" ) 
  {
      REQUIRE( valid_engine->readCodeTable(wrong_game_code_table) == Error );
  } // SECTION( "An engine can be read one char code table and return Error if not correct" )

  SECTION( "An engine can be read one char code table and add pieces to it" ) 
  {
      Board::getBoard()->cleanBoard();
      REQUIRE( valid_engine->readCodeTable(initial_game_code_table) == Success );
      REQUIRE( Board::getBoard()->getSquareAt(1,0)->isOccupied() == true );
  } // SECTION( "An engine can be read one char code table and add pieces to it" )

  SECTION( "An engine can be read one char code table and add a specific piece to it" ) 
  {
      PKing   test_king_piece( new King() );
      PQueen  test_queen_piece( new Queen() );
      PBishop test_bishop_piece( new Bishop() );
      PKnight test_knight_piece( new Knight() );
      PRook   test_rook_piece( new Rook() );
      PPawn   test_pawn_piece( new Pawn() );

      Board::getBoard()->cleanBoard();
      REQUIRE( valid_engine->readCodeTable( game_with_one_kind_of_piece_code_table ) == Success );
      REQUIRE( Board::getBoard()->getSquareAt(7,4)->isOccupied() == true );

      //Now we assure that the piece set was specific a king
      REQUIRE( ((King*)(Board::getBoard()->getSquareAt(7,4)->getPiece().get()))->isKing );
      valid_engine->printCodeTable( game_with_one_kind_of_piece_code_table );
      
  } // SECTION( "An engine can be read one char code table and add a specific piece to it" )
  
} //TEST_CASE( "Read Engine", "[Engine]" ) 

TEST_CASE( "Update Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Engine
  // These tests will focus on:
  
} // TEST_CASE( "Update", "[Engine]" ) 

TEST_CASE( "Destroy Engine", "[Engine]" ) 
{
  //! These test case will focus on methods that
  //! updates Engine
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Engine]" ) 