#include "board.hpp"

typedef shared_ptr<Board> PBoard;

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
      REQUIRE(Board::getBoard()->getBoardSquareAt( 2, 3 )->getRank() == 3 );
      REQUIRE(Board::getBoard()->getBoardSquareAt( 2, 2 )->getRank() == 2 );

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
  } // SECTIONSECTION( "A board throws an error if wrong coordinates passed to read one of it's squares " ) 

} // TEST_CASE( "Read", "[board]" )

TEST_CASE( "Update Board", "[board]" ) 
{ 
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:

} // TEST_CASE( "Update", "[board]" ) 

TEST_CASE( "Destroy Board", "[board]" ) 
{
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[board]" ) 