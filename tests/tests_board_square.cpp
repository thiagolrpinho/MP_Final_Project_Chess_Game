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
  BoardSquare* board_square_a7_coordinates = new BoardSquare(1,7);

  SECTION( "A new created BoardSquare can have it's coordinates read" ) 
  {
    REQUIRE( board_square_a7_coordinates->getFile() == 1 );
    REQUIRE( board_square_a7_coordinates->getRank() == 7 );
  } // SECTION( "A new created BoardSquare can have it's coordinates read" )

  SECTION( "A new board square cannot have a rank above 8 or bellow 1" ) 
  { 
    //A board can only have 8x8 squares so a wrongly created square could 
    //risk a bug.
    try {
      BoardSquare* board_square_wrong_rank_bellow_1 = new BoardSquare( 1, 0 );
      //If this lines happens, it's surely a mistake
      REQUIRE_FALSE( "The Board square have a lower than 1 rank." );
    } catch (int e) {
      REQUIRE( "The board square cannot be created with a lower than 1 rank" );
    }

     try {
      BoardSquare* board_square_wrong_rank_above_8 = new BoardSquare( 1, 10 );
      //If this lines happens, it's surely a mistake
      REQUIRE_FALSE( "The Board square have a higher than 8 rank." );
    } catch (int e) {
      REQUIRE( "The board square cannot be created with a higher than 8 rank." );
    }

  } // SECTION( "A new created BoardSquare can have it's coordinates read" )

  SECTION( "A new board square cannot have a file above 8 or bellow 1" ) 
  { 
    //A board can only have 8x8 squares so a wrongly created square could 
    //risk a bug.
    try {
      BoardSquare* board_square_wrong_file_bellow_1 = new BoardSquare( -1, 7 );
      //If this lines happens, it's surely a mistake
      REQUIRE_FALSE( "The Board square have a lower than 1 rank." );
    } catch (int e) {
      REQUIRE( "The board square cannot be created with a lower than 1 rank" );
    }

     try {
      BoardSquare* board_square_wrong_file_above_8 = new BoardSquare( 10, 7 );
      //If this lines happens, it's surely a mistake
      REQUIRE_FALSE( "The Board square have a higher than 8 rank." );
    } catch (int e) {
      REQUIRE( "The board square cannot be created with a higher than 8 rank." );
    }

  } // SECTION( "A new created BoardSquare can have it's coordinates read" )

  SECTION( "A new board square points has no piece" ) 
  { 
    //A board square should point to a pieace or to null. When it's
    //created there shouldn't be a pieace over it.
    REQUIRE( board_square_a7_coordinates->getPiece() == NULL );
  } // SECTION( "A new board square points has no piece" ) 

}

TEST_CASE( "Read", "[square]" ) 
{ 
  //! These test case will focus on methods that
  //! reads board squares

  BoardSquare* non_occupied_board_square = new BoardSquare( 1, 1 );
  BoardSquare* occupied_board_square = new BoardSquare( 1, 2 );
  Piece* empty_piece = new Piece();

  occupied_board_square->setPiece(empty_piece);

  SECTION( "A board square can be read to know if it's occupied" ) 
  { 
    // If there's no pieace ver it, it's not occupied
    REQUIRE( non_occupied_board_square->isOccupied() == false );
    REQUIRE( occupied_board_square->isOccupied() == true );

  } // SECTION( "A board square can be read to know if it's occupied" ) 


}

TEST_CASE( "Update", "[square]" ) 
{ 
}
TEST_CASE( "Destroy", "[square]" ) 
{ 
}