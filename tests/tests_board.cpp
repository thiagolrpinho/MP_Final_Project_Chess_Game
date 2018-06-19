#include "board_square.hpp"


//! These tests will be focused on board class
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create", "[board]" ) 
{ 
  //! These test case will focus on methods that
  //! creates objects within board class
  // These tests will focus on:
 
} // TEST_CASE( "Create", "[board]" )

TEST_CASE( "Read", "[board]" ) 
{ 
   SECTION( "A board can have it's address returned" ) 
  {
    REQUIRE_FALSE( Board::getBoard() == nullptr );
  } // SECTION( "A board can have it's address returned" )
} // TEST_CASE( "Read", "[board]" )

TEST_CASE( "Update", "[board]" ) 
{ 
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:

} // TEST_CASE( "Update", "[board]" ) 

TEST_CASE( "Destroy", "[board]" ) 
{
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[board]" ) 