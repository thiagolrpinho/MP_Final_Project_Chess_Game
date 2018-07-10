#include "engine.hpp"
#include <typeinfo>

typedef shared_ptr<Engine>  PEngine;
typedef shared_ptr<Piece>   PPiece;
typedef shared_ptr<King>    PKing;
typedef shared_ptr<Queen>   PQueen;
typedef shared_ptr<Bishop>  PBishop;
typedef shared_ptr<Knight>  PKnight;
typedef shared_ptr<Rook>    PRook;
typedef shared_ptr<Pawn>    PPawn;
typedef unique_ptr<unique_ptr<char[]>[]> PCodeTable;

//! These tests will be focused on engine class
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! creates objects within Engine class
  // These tests will focus on:./
} // TEST_CASE( "Create", "[Engine]" )

TEST_CASE( "Read Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! reads objects within Engine class
  // These tests will focus on:./

} //TEST_CASE( "Read Engine", "[Engine]" ) 

TEST_CASE( "Update Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Engine
  // These tests will focus on:
  
} // TEST_CASE( "Update", "[Engine]" ) 

TEST_CASE( "Destroy Engine", "[Engine]" ) 
{
  //! These test case will focus on methods that
  //! updates Engine
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Engine]" ) 