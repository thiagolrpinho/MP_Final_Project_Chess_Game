#include "square.hpp"

typedef shared_ptr<Pawn> PPawn;
typedef shared_ptr<Square> PSquare;

//! These tests will be focused on squares
//! They'll be considered fully functional if they pass in
//! four test cases: Create, Read, Update and Destroy

TEST_CASE( "Create", "[square]" ) 
{ 
  //! These test case will focus on methods that
  //! create new squares.
  // These tests will focus on:
  // Square::Square( unsigned short , unsigned short int))
  // unsigned short int Square::getHorizontal()
  // unsigned short int Square::getVertical()

  //A square can be created with a respective vertical(column)
  //and horizontal(row)
  PSquare square_a7_coordinates(  new Square( 7 , 1 ) );

  SECTION( "A new created Square can have it's coordinates read" ) 
  {
    REQUIRE( square_a7_coordinates->getVertical() == 1 );
    REQUIRE( square_a7_coordinates->getHorizontal() == 7 );
  } // SECTION( "A new created Square can have it's coordinates read" )

  SECTION( "A new square cannot have a horizontal above maximum allowed or bellow 1" ) 
  { 
    //A board can only have maximum allowedxmaximum allowed squares so a wrongly created square could 
    //risk a bug.
    try {
      PSquare square_wrong_horizontal_bellow_minimum_allowed(  new Square(  1, -1 ) );
    } catch (int e) {
      REQUIRE( "The square cannot be created with a lower than minimum allowed horizontal" );
    }

     try {
      PSquare square_wrong_horizontal_above_maximum_allowed(  new Square(  1, 10 ) );
    } catch (int e) {
      REQUIRE( "The square cannot be created with a higher than maximum allowed horizontal." );
    }

  } // SECTION( "A new created Square can have it's coordinates read" )

  SECTION( "A new square cannot have a vertical above maximum allowed or bellow minimum allowed" ) 
  { 
    //A board can only have maximum allowedxmaximum allowed squares so a wrongly created square could 
    //risk a bug.
    try {
      PSquare square_wrong_vertical_bellow_minimum_allowed(  new Square(  -1,  7 ) );
    } catch (int e) {
      REQUIRE( "The square cannot be created with a lower than minimum allowed horizontal" );
    }

     try {
      PSquare square_wrong_vertical_above_maximum_allowed(  new Square(  10, 7 ) );
    } catch (int e) {
      REQUIRE( "The square cannot be created with a higher than maximum allowed horizontal." );
    }
    
  } // SECTION( "A new created Square can have it's coordinates read" )

  SECTION( "A new square points has no piece" ) 
  { 
    //A square should point to a piece or to null. When it's
    //created there shouldn't be a piece over it.
    REQUIRE( square_a7_coordinates->getPiece() == nullptr );
  } // SECTION( "A new square points has no piece" ) 

} // TEST_CASE( "Create", "[square]" )

TEST_CASE( "Read", "[square]" ) 
{ 
  //! These test case will focus on methods that
  //! reads squares
  // These tests will focus on:
  // unsigned short int Square::setPiece(Pawn *)
  // Pawn * Square::getPiece()

  PSquare non_occupied_square(  new Square( 1, 1 ) );
  PSquare occupied_square(  new Square( 1, 2 ) );
  PPawn empty_piece( new Pawn() );

  occupied_square->setPiece( empty_piece );

  SECTION( "A square can be read to know if it's occupied" ) 
  { 
    // If there's no piece over it, it's not occupied
    REQUIRE( non_occupied_square->isOccupied() == false );
    REQUIRE( occupied_square->isOccupied() == true );

  } // SECTION( "A square can be read to know if it's occupied" ) 

  SECTION( "A square can be read to know who is occupying it" ) 
  { 
    // If there's no piece ver it, it should return nullptr
    REQUIRE( non_occupied_square->getPiece() == nullptr );
    //There's it should return a pointer to the piece.
    REQUIRE( occupied_square->getPiece() == empty_piece );

  } // SECTION( "A square can be read to know who is occupying it" )  
  
} // TEST_CASE( "Read", "[square]" )

TEST_CASE( "Update", "[square]" ) 
{ 
  //! These test case will focus on methods that
  //! updates squares
  // These tests will focus on:
  // unsigned short int Square::setPiece(Pawn *)

  PSquare non_occupied_square(  new Square( 1, 2 ) );

  SECTION( "A square can be set a new piece" ) 
  { 
    PPawn first_piece( new Pawn() );
    PPawn second_piece( new Pawn() );
    // First we test if a non occupied square receive a piece.
    REQUIRE( non_occupied_square->setPiece(first_piece) == Success);

    PSquare occupied_square = non_occupied_square;

    // Then we test if a an occupied square can receive a new piece.
    REQUIRE( occupied_square->setPiece(second_piece) == Success );

  } // SECTION( "A square can be set a new piece" ) 

} // TEST_CASE( "Update", "[square]" ) 

TEST_CASE( "Destroy", "[square]" ) 
{
  //! These test case will focus on methods that
  //! updates squares
  // These tests will focus on:
  // Square::~Square()

  PSquare occupied_square(  new Square( 5, 5 ) );
  PPawn piece_to_be_destroyed( new Pawn() );
  occupied_square->setPiece(piece_to_be_destroyed);

  SECTION( "A square can be deleted and no piece will be left floating" ) 
  { 
    try {
      occupied_square.reset();
      REQUIRE( "The square was succesfully deleted" );
      // Using smart shared pointer I can only guarantee that the reference on square
      // was erased and if there were no other reference to it it'll be succesfully
      // deallocated.
    } catch (int e) {
      REQUIRE_FALSE( "Something wrong ocurred when square was being deleted" );
    }
    
  } // SECTION( "A square can be deleted and no piece will be left floating" ) 

  SECTION( "A square can have it's piece deleted if it need to." ) 
  {
    REQUIRE( occupied_square->deletePiece() == Success );
    REQUIRE( occupied_square->getPiece() == nullptr );
  } // SECTION( "A square can have it's piece deleted if it need to." ) 
   
} // TEST_CASE( "Destroy", "[square]" ) 