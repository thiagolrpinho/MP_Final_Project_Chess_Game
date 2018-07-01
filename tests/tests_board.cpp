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
    } catch (int e){
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