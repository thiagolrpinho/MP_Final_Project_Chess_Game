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
  REQUIRE( a7->getFile() == 1 );
  REQUIRE( a7->getRank() == 7 );
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