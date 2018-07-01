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
      REQUIRE( Board::getBoard()->getBoardSquareAt( 3 , 2 )->getHorizontal() == 3 );
      REQUIRE( Board::getBoard()->getBoardSquareAt( 2 , 2 )->getHorizontal() == 2 );

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

  SECTION( "The board returns true if a given horizontal path right is free " ) 
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

  SECTION( " The board returns false if a given horizontal path right is not free " ) 
  {
    try {
      PPiece piece_on_A6( new Piece() );
      //A6 on a matrix 0 to 7 is [0][5]
      PPiece piece_on_E6( new Piece() );
      //E6 on a matrix 0 to 7 is [4][5]

      REQUIRE( Board::getBoard()->setPieceAt( 0, 5 , piece_on_A6 ) == Success );
      REQUIRE( Board::getBoard()->setPieceAt( 4, 5 , piece_on_E6 ) == Success );

      //Verifying if is clear the path A6 to H6
      REQUIRE( Board::getBoard()->isClearHorizontal(0, 5, 7) == false );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board returns true if a given horizontal path right is free" );
    }
  } // SECTION( " The board returns false if a given horizontal path right is not free " )

  SECTION( " The board returns true or false if a given horizontal path left is free or not respectively " ) 
  {
    try {
      PPiece piece_on_A5( new Piece() );
      //A5 on a matrix 0 to 7 is [0][4]
      PPiece piece_on_F5( new Piece() );
      //E5 on a matrix 0 to 7 is [4][4]

      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );
      REQUIRE( Board::getBoard()->setPieceAt( 4, 4 , piece_on_F5 ) == Success );

      //Verifying if is clear the path H5 to D5
      REQUIRE( Board::getBoard()->isClearHorizontal(7, 4, 3 ) == false );

      //Verifying if is clear the path H5 to F5
      REQUIRE( Board::getBoard()->isClearHorizontal(7, 4, 5) == true );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( " The board doesn't return true or false if a given horizontal path left is free or not respectively " );
    }
  } // SECTION( " The board returns true or false if a given 
    //  horizontal path left is free or not respectively " ) 

  SECTION( "The board returns true if a given vertical path up is free " ) 
  {
    try {
      PPiece piece_on_A5( new Piece() );
      //A5 on a matrix 0 to 7 is [0][4]
      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );

      REQUIRE( Board::getBoard()->getBoardSquareAt( 0 , 4)->isOccupied() == true );
      REQUIRE( Board::getBoard()->getBoardSquareAt( 0 , 5)->isOccupied() == false );
      REQUIRE( Board::getBoard()->getBoardSquareAt( 0 , 6)->isOccupied() == false );
      REQUIRE( Board::getBoard()->getBoardSquareAt( 0 , 7)->isOccupied() == false );

      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );
      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );

      //Verifying if is clear the path A5 to A8
      REQUIRE( Board::getBoard()->isClearVertical(0, 4, 7) == true );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board returns true if a given vertical path up is free" );
    }
  } // SECTION( "The board returns true if a given vertical path up is free " ) 

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

  SECTION( "A board can be deleted and no board squares will be left floating" ) 
  { 
    try {
      REQUIRE_FALSE( Board::getBoard() == nullptr );
      Board::getBoard().reset();
      // Using smart shared pointer I can only guarantee that the reference on board square
      // was erased and if there were no other reference to it it'll be succesfully
      // deallocated.
    } catch (int e) {
      REQUIRE_FALSE( "Something wrong ocurred when board was being deleted" );
    }
    
  } // SECTION( "A board square can be deleted and no piece will be left floating" ) 

} // TEST_CASE( "Destroy", "[board]" ) 