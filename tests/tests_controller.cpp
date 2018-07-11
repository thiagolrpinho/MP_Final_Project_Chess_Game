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

  SECTION( "A Controller can see if an edited board is valid " ) 
  {
    const char invalid_two_queen_edited_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      { 'R'},
      { },
      { 0, 0, 'r'},
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 'z', 'b', 'c', 't'}
    };

    REQUIRE_FALSE( Controller::getController()->validateBoard( invalid_two_queen_edited_code_table ) == true );
  } // SECTION( "A Controller can see if an edited board is valid "  )

} //TEST_CASE( "Read Controller", "[Controller]" ) 

TEST_CASE( "Update Controller", "[Controller]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Controller
  // These tests will focus on:
   SECTION( "A Controller can see if an edited board is valid " ) 
  { 
    const char actual_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  
      { },
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };

    const char new_move_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  
      { },
      { },
      { 0, 0, 'c'}, // Horse can jump
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 'z', 'b', 'c', 't'}
    };
    Engine::getEngine()->readCodeTable( actual_code_table );

    Controller::getController()->movePiece( new_move_code_table );

    PCodeTable returned_code_table = Engine::getEngine()->returnCodeTable();
    
    REQUIRE( returned_code_table[2][2] != actual_code_table[2][2] );
    REQUIRE( returned_code_table[0][1] != actual_code_table[0][1] );
  } // SECTION( "A Controller can see if an edited board is valid "  )
  
} // TEST_CASE( "Update", "[Controller]" ) 

TEST_CASE( "Destroy Controller", "[Controller]" ) 
{
  //! These test case will focus on methods that
  //! updates Controller
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Controller]" ) 