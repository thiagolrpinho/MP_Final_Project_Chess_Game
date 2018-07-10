#include "piece.hpp"
#include "board.hpp"
#include <typeinfo>

typedef shared_ptr<Piece>   PPiece;
typedef shared_ptr<King>    PKing;
typedef shared_ptr<Queen>   PQueen;
typedef shared_ptr<Bishop>  PBishop;
typedef shared_ptr<Knight>  PKnight;
typedef shared_ptr<Rook>    PRook;
typedef shared_ptr<Pawn>    PPawn;
typedef unique_ptr<unique_ptr<char[]>[]> PCodeTable;

//! These tests will be focused on Piece class
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create Pieces", "[Pieces]" ) 
{ 
  //! These test case will focus on methods that
  //! creates objects within Pieces class
  // These tests will focus on:./
} // TEST_CASE( "Create", "[Pieces]" )

TEST_CASE( "Read Pieces", "[Pieces]" ) 
{ 
  //! These test case will focus on methods that
  //! reads objects within Pieces class
  // These tests will focus on:./

  SECTION( "An Piece can say if a valid coordinate is a valid move" ) 
  {
    Board::getBoard()->cleanBoard();
    PPawn pawn_to_be_moved( new Pawn() );
    Board::getBoard()->setPieceAt( 0, 1 , pawn_to_be_moved );
  
    /*
      {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 0, 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      { 'P', }, // This is a valid move
      { },
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
    REQUIRE( pawn_to_be_moved->canMoveTo( 0, 1, 0, 2) == true );
    
    /*
      {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 0, 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      { 0, }, 
      {'P'}, // This is a valid move
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
    REQUIRE( pawn_to_be_moved->canMoveTo( 0, 1, 0, 3) == true );

    Board::getBoard()->cleanBoard();
    pawn_to_be_moved.reset( new Pawn() );
    Board::getBoard()->setPieceAt( 0, 1 , pawn_to_be_moved );
        /*
      {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 0, 'P', 'P', 'P', 'P', 'P', 'P'},
      { 'P', }, // This is not a valid move
      { }, 
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
    REQUIRE_FALSE( pawn_to_be_moved->canMoveTo( 1, 1, 0, 2) == true );

      /*
      {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      { }, 
      { }, 
      { },
      {'p'}, // This is a valid move
      { 0, 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
    REQUIRE( pawn_to_be_moved->canMoveTo( 0, 6, 0, 5 ) == true );

          /*
      {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      { }, 
      { }, 
      { 'p' },
      { }, // This is a valid move
      { 0, 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
    REQUIRE( pawn_to_be_moved->canMoveTo( 0, 6, 0, 4 ) == true );

      /*
      {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      { }, 
      { }, 
      { },
      { 'p'}, // This is a valid move
      { 'p', 0, 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
     REQUIRE_FALSE( pawn_to_be_moved->canMoveTo( 1, 6, 0, 5 ) == true );
  } // An Piece can say if a same code table is a valid state change"


} //TEST_CASE( "Read Pieces", "[Pieces]" ) 

TEST_CASE( "Update Pieces", "[Pieces]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Pieces
  // These tests will focus on:
  
} // TEST_CASE( "Update", "[Pieces]" ) 

TEST_CASE( "Destroy Pieces", "[Pieces]" ) 
{
  //! These test case will focus on methods that
  //! updates Pieces
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Pieces]" ) 