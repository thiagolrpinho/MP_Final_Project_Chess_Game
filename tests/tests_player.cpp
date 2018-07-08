#include "player.hpp"


//! These tests will be focused on engine class
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create Player", "[Player]" ) 
{ 
  //! These test case will focus on methods that
  //! creates objects within Player class
  // These tests will focus on:./
  SECTION( "A valid player can be created ")
  {
    Player * valid_player = nullptr;
    King& valid_king = new King(true);
    set<Piece*>& set_of_pieces = new set<Piece>;
    string name = "joseph";

    valid_player = new Player( name, true, valid_king, set_of_pieces );

    REQUIRE_FALSE( valid_player == nullptr );
  }
} // TEST_CASE( "Create", "[Player]" )

TEST_CASE( "Read Player", "[Player]" ) 
{ 
  //! These test case will focus on methods that
  //! reads objects within Player class
  // These tests will focus on:./

} //TEST_CASE( "Read Player", "[Player]" ) 

TEST_CASE( "Update Player", "[Player]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Player
  // These tests will focus on:
  
} // TEST_CASE( "Update", "[Player]" ) 

TEST_CASE( "Destroy Player", "[Player]" ) 
{
  //! These test case will focus on methods that
  //! updates Player
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Player]" ) 