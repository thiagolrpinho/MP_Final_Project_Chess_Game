#include "board_square.hpp"

//! These tests will be focused on board squares
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create", "[square]" ) 
{ 
  //! These test case will focus on methods that
  //! create new squares.

  //A square can be created with a respective file(column)
  //and rank(row)
  BoardSquare* a7 = new BoardSquare(1,7);

  SECTION( "A new created BoardSquare can have it's coordinates read" ) 
  {
    REQUIRE( a7->getFile() == 1 );
    REQUIRE( a7->getRank() == 7 );
  } // SECTION( "A new created BoardSquare can have it's coordinates read" )

  SECTION( "A new board square cannot have a rank above 8 or bellow 1" ) 
  { 
    //A board can only have 8x8 squares so a wrongly created square could 
    //risk a bug.
    try {
      BoardSquare* a8 = new BoardSquare(1,-3);
      //If this lines happens, it's surely a mistake
      REQUIRE_FALSE( "The Board square have a lower than 1 rank." );
    } catch (int e) {
      REQUIRE( "The board square cannot be created with a lower than 1 rank" );
    }
  } // SECTION( "A new created BoardSquare can have it's coordinates read" )

}

TEST_CASE( "Read", "[square]" ) 
{ 
}

TEST_CASE( "Update", "[square]" ) 
{ 
}
TEST_CASE( "Destroy", "[square]" ) 
{ 
}