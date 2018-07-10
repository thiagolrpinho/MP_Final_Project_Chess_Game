#include "controller.hpp"

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

TEST_CASE( "Create Controller", "[Controller]" ) 
{ 
  //! These test case will focus on methods that
  //! creates objects within Controller class
  // These tests will focus on:./
} // TEST_CASE( "Create", "[Controller]" )

TEST_CASE( "Read Controller", "[Controller]" ) 
{ 
  //! These test case will focus on methods that
  //! reads objects within Controller class
  // These tests will focus on:./
  SECTION( "A Controller can have it's address returned" ) 
  {
    REQUIRE_FALSE( Controller::getController() == nullptr );
  } // SECTION( "A Controller can have it's address returned" )

} //TEST_CASE( "Read Controller", "[Controller]" ) 

TEST_CASE( "Update Controller", "[Controller]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Controller
  // These tests will focus on:
  
} // TEST_CASE( "Update", "[Controller]" ) 

TEST_CASE( "Destroy Controller", "[Controller]" ) 
{
  //! These test case will focus on methods that
  //! updates Controller
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Controller]" ) 