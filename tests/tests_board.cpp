#include "board.hpp"

typedef shared_ptr<Board> PBoard;
typedef shared_ptr<Piece> PPiece;

//! These tests will be focused on board class
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create Board", "[board]" ) 
{ 

  //! These test case will focus on methods that
  //! creates objects within board class
  // These tests will focus on:./

  SECTION( "A board can be successfully created" ) 
  {
    try {
      PBoard one_valid_board( new Board());
      REQUIRE_FALSE( one_valid_board == nullptr );  
    } catch (int e) {
      REQUIRE_FALSE( "The Board cannot be succesfully created." );
    }
  } // SECTION( "A board can be successfully created" )
 
} // TEST_CASE( "Create", "[board]" )

TEST_CASE( "Read Board", "[board]" ) 
{ 
  SECTION( "A board can have it's address returned" ) 
  {
    REQUIRE_FALSE( Board::getBoard() == nullptr );
  } // SECTION( "A board can have it's address returned" )

  SECTION( "A board can read one of it's squares " ) 
  {
    try {
      //Board can read a valid square
      REQUIRE_FALSE( Board::getBoard()->getBoardSquareAt( 2, 3 ) == nullptr );

      //Board read a square with given coordinates
      REQUIRE( Board::getBoard()->getBoardSquareAt( 2, 3 )->getRank() == 3 );
      REQUIRE( Board::getBoard()->getBoardSquareAt( 2, 2 )->getRank() == 2 );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "Error on reading one of it's squares" );
    }
  } // SECTION( "A board can read one of it's squares" )

  SECTION( "A board throws an error if wrong coordinates passed to read one of it's squares " ) 
  {
    try {
      PBoardSquare wrong_board_square( Board::getBoard()->getBoardSquareAt( 9, 2 ) );
      REQUIRE_FALSE( "No error on reading wrong square" );
    } catch (int throwned_error )
    {
      REQUIRE( "Error on reading wrong square" );
    }

    try {
      PBoardSquare wrong_board_square( Board::getBoard()->getBoardSquareAt( -1, 2 ) );
      REQUIRE_FALSE( "No error on reading wrong square" );
    } catch (int throwned_error )
    {
      REQUIRE( "Error on reading wrong square" );
    }
  } // SECTION( "A board throws an error if wrong coordinates passed to read one of it's squares " ) 

  SECTION( "The board returns true if a given horizontal path up is free " ) 
  {
    try {
      PPiece piece_on_A5( new Piece() );
      //A5 on a matrix 0 to 7 is [0][4]
      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );

      //Verifying if is clear the path A5 to H5
      REQUIRE( Board::getBoard()->isClearHorizontal(0, 4, 7) == true );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board returns true if a given horizontal path up is free" );
    }
  } // SECTION( "The board returns true if a given horizontal path up is free " ) 

  SECTION( "The board returns false if a given horizontal path up is not free " ) 
  {
    try {
      PPiece piece_on_A5( new Piece() );
      PPiece piece_on_F5( new Piece() );
      //A5 on a matrix 0 to 7 is [0][4]
      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );
      REQUIRE( Board::getBoard()->setPieceAt( 6, 4 , piece_on_A5 ) == Success );

      //Verifying if is clear the path A5 to H5
      REQUIRE( Board::getBoard()->isClearHorizontal(0, 4, 7) == true );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board returns true if a given horizontal path up is free" );
    }
  } // SECTION( "A board can read one of it's squares" )
} // TEST_CASE( "Read", "[board]" )

TEST_CASE( "Update Board", "[board]" ) 
{ 
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:
  SECTION( "A board can change of it's board squares pieces " ) 
  {
    try {
      PPiece piece_to_be_set_on_square( new Piece() );

      REQUIRE( Board::getBoard()->setPieceAt( 2, 3 , piece_to_be_set_on_square ) == Success );
      
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "Error on changing one of it's squares" );
    }
  } // SECTION( "A board can change of it's board squares pieces " )

  SECTION( "A board return an Error if wrong square is given " ) 
  {
      PPiece piece_to_be_set_on_square( new Piece() );

      REQUIRE( Board::getBoard()->setPieceAt( 9, 3 , piece_to_be_set_on_square ) == Error );
  } // SECTION( "A board return an Error if wrong square is given " )

} // TEST_CASE( "Update", "[board]" ) 

TEST_CASE( "Destroy Board", "[board]" ) 
{
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[board]" ) 