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
    PPawn white_pawn( new Pawn() );
    Board::getBoard()->setPieceAt( 0, 1 , white_pawn );
  
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
    REQUIRE( white_pawn->canMoveTo( 0, 1, 0, 2) == true );
    
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
    REQUIRE( white_pawn->canMoveTo( 0, 1, 0, 3) == true );

    Board::getBoard()->cleanBoard();
    white_pawn.reset( new Pawn() );
    Board::getBoard()->setPieceAt( 0, 1 , white_pawn );
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
    REQUIRE_FALSE( white_pawn->canMoveTo( 1, 1, 0, 2) == true );

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
    REQUIRE( white_pawn->canMoveTo( 0, 6, 0, 5 ) == true );

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
    REQUIRE( white_pawn->canMoveTo( 0, 6, 0, 4 ) == true );

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
     REQUIRE_FALSE( white_pawn->canMoveTo( 1, 6, 0, 5 ) == true );
  } // An Piece can say if a same code table is a valid state change"

  SECTION( "A King can say if it's in check when alone" ) 
  {
    Board::getBoard()->cleanBoard();
    PKing white_king( new King() );
    Board::getBoard()->setPieceAt( 0, 1 , white_king );

    REQUIRE_FALSE( white_king->inCheck() == true );
  }

  SECTION( "A King can say if it's in check with allied pieces" ) 
  {
    Board::getBoard()->cleanBoard();
    PKing white_king_not_in_check( new King() );
    PRook white_king( new Rook() );
    PBishop white_bishop( new Bishop() );

    Board::getBoard()->setPieceAt( 4, 4 , white_king_not_in_check );
    Board::getBoard()->setPieceAt( 3, 4 , white_king );
    Board::getBoard()->setPieceAt( 3, 3 , white_bishop );

    REQUIRE_FALSE( white_king_not_in_check->inCheck() == true );
  }

    SECTION( "A King can say if it's in check with enemy pieces" ) 
  {
    Board::getBoard()->cleanBoard();
    PKing white_king_in_check( new King() );
    PRook black_rook( new Rook( false ) );
    PBishop black_bishop( new Bishop( false ) );

    Board::getBoard()->setPieceAt( 4, 4 , white_king_in_check );
    Board::getBoard()->setPieceAt( 3, 4 , black_rook );
    Board::getBoard()->setPieceAt( 3, 3 , black_bishop );

    REQUIRE( white_king_in_check->inCheck() == true );
  }

    SECTION( "A Rook can eat a pawn" ) 
  {
    Board::getBoard()->cleanBoard();
    PRook white_rook( new Rook() );
    PPawn black_pawn( new Pawn( false ) );

    Board::getBoard()->setPieceAt( 0, 1 , white_rook );
    REQUIRE( white_rook->canMoveTo( 0, 1, 5, 1 ) == true );
    REQUIRE( white_rook->canMoveTo( 0, 1, 0, 6 ) == true );
    REQUIRE( white_rook->canMoveTo( 0, 1, 0, 2 ) == true );

    Board::getBoard()->setPieceAt( 0, 2 , black_pawn );

    REQUIRE( white_rook->canMoveTo( 0, 1, 0, 2 ) == true );
  }

  SECTION( "A Rook can eat a bishop" ) 
  {
    Board::getBoard()->cleanBoard();
    PRook white_rook( new Rook() );
    PBishop black_bishop( new Bishop( false ) );

    Board::getBoard()->setPieceAt( 0, 1 , white_rook );
    REQUIRE( white_rook->canMoveTo( 0, 1, 5, 1 ) == true );
    REQUIRE( white_rook->canMoveTo( 0, 1, 0, 6 ) == true );
    REQUIRE( white_rook->canMoveTo( 0, 1, 0, 2 ) == true );

    Board::getBoard()->setPieceAt( 5, 1 , black_bishop );

    REQUIRE( white_rook->canMoveTo( 0, 1, 5, 1 ) == true );
  }

  SECTION( "A Bishop can eat a rook" ) 
  {
    Board::getBoard()->cleanBoard();
    PRook white_rook( new Rook() );
    PBishop black_bishop( new Bishop( false ) );

    Board::getBoard()->setPieceAt( 5, 1 , black_bishop );
    REQUIRE( black_bishop->canMoveTo( 5, 1, 6, 0 ) == true );

    Board::getBoard()->setPieceAt( 6, 0, white_rook );
    REQUIRE( black_bishop->canMoveTo( 5, 1, 6, 0 ) == true );
  }

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