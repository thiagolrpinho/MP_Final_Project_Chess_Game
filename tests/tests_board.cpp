#include "board.hpp"

typedef shared_ptr<Board> PBoard;
typedef shared_ptr<Bishop> PBishop;

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
  //! These test case will focus on methods that
  //! reads objects within board class
  // These tests will focus on:
  // static shared_ptr<Board> getBoard();
  // PSquare getSquareAt(uint8_t horizontal_coordinate, uint8_t vertical_coordinate );
  // bool isClearHorizontal(uint8_t actual_horizontal_coordinate, 
  //           uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate) const;
  //bool isClearVertical(uint8_t actual_horizontal_coordinate,
  //           uint8_t actual_vertical_coordinate, uint8_t future_vertical_coordinate) const;
  //bool isClearDiagonal(uint8_t actual_horizontal_coordinate,
  //           uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
  //           uint8_t future_vertical_coordinate ) const;
  //bool isEndRow(uint8_t actual_horizontal_coordinate,
  //           uint8_t actual_vertical_coordinate) const;

  SECTION( "A board can have it's address returned" ) 
  {
    REQUIRE_FALSE( Board::getBoard() == nullptr );
  } // SECTION( "A board can have it's address returned" )

  SECTION( "A board can read one of it's squares " ) 
  {
    try {
      //Board can read a valid square
      REQUIRE_FALSE( Board::getBoard()->getSquareAt( 2, 3 ) == nullptr );

      //Board read a square with given coordinates
      REQUIRE( Board::getBoard()->getSquareAt( 3 , 2 )->getHorizontal() == 3 );
      REQUIRE( Board::getBoard()->getSquareAt( 2 , 2 )->getHorizontal() == 2 );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "Error on reading one of it's squares" );
    }
  } // SECTION( "A board can read one of it's squares" )

  SECTION( "A board throws an error if wrong coordinates passed to read one of it's squares " ) 
  {
    try {
      PSquare wrong_square( Board::getBoard()->getSquareAt( 9, 2 ) );
    } catch (int throwned_error )
    {
      REQUIRE( "Error on reading wrong square" );
    }

    try {
      PSquare wrong_square( Board::getBoard()->getSquareAt( -1, 2 ) );
    } catch (int throwned_error )
    {
      REQUIRE( "Error on reading wrong square" );
    }
  } // SECTION( "A board throws an error if wrong coordinates passed to read one of it's squares " ) 

  SECTION( "The board returns true if a given horizontal path right is free " ) 
  {
    try {
      PBishop piece_on_A5( new Bishop() );
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
      PBishop piece_on_A6( new Bishop() );
      //A6 on a matrix 0 to 7 is [0][5]
      PBishop piece_on_E6( new Bishop() );
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
      PBishop piece_on_A5( new Bishop() );
      //A5 on a matrix 0 to 7 is [0][4]
      PBishop piece_on_F5( new Bishop() );
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

  SECTION( " The board returns true or false if a given vertical path up is free or not respectively " ) 
  {
    try {

      PBoard valid_board = Board::getBoard();
      PBishop piece_on_A5( new Bishop() );
      //A5 on a matrix 0 to 7 is [0][4]
      
      REQUIRE( valid_board->cleanBoard() == Success );

      REQUIRE( valid_board->setPieceAt( 0, 4 , piece_on_A5 ) == Success );

      //Verifying if is clear the path A5 to A8
      REQUIRE( valid_board->isClearVertical(0, 4, 7) == true );
      //Verifying if is clear the path A3 to A8
      REQUIRE( valid_board->isClearVertical(0, 2, 7) == false );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't returns true or false if a given vertical path up is free or not respectively " );
    }
  } // " The board returns true or false if a given vertical path up is free or not respectively " ) 

  SECTION( " The board returns true or false if a given vertical path down is free or not respectively " ) 
  {
    try {
      PBishop piece_on_A5( new Bishop() );
      //A5 on a matrix 0 to 7 is [0][4]
      PBishop piece_on_A0( new Bishop() );
      //A0 on a matrix 0 to 7 is [0][0]

      REQUIRE( Board::getBoard()->setPieceAt( 0, 4 , piece_on_A5 ) == Success );
      REQUIRE( Board::getBoard()->setPieceAt( 0, 0 , piece_on_A0 ) == Success );

      //Verifying if is clear the path A8 to A4
      REQUIRE( Board::getBoard()->isClearVertical(0, 7, 3 ) == false );

      //Verifying if is clear the path A8 to A6
      REQUIRE( Board::getBoard()->isClearVertical(0, 7, 5) == true );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( " The board doesn't return true or false if a given vertical path down is free or not respectively " );
    }
  } // SECTION( " The board returns true or false if a given 
    //  vertical path down is free or not respectively " ) 

  SECTION( " The board returns false if a horizontal movement starts and ends on the same spot " ) 
  {
    PBoard valid_board = Board::getBoard();

    PBishop piece_on_F7( new Bishop() );
      //F7 on a matrix 0 to 7 is [5][6]
    try {
      // First we make sure the board is clean
      REQUIRE( valid_board->cleanBoard() == Success );

      // Then we check if even if there are no pieces over F7 it should still return Error.
      REQUIRE( valid_board->isClearHorizontal( 5, 6, 5) == false );

      REQUIRE( valid_board->setPieceAt( 0, 4 , piece_on_F7 ) == Success );

      // After that we check if with a piece over F7 would return Error
      REQUIRE( valid_board->isClearHorizontal( 5, 6, 5) == false );
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return false if a horizontal movement starts and ends on the same spot" );
    }
  } // SECTION( " The board returns false if a horizontal movement starts and ends on the same spot ")

  SECTION( " The board returns false if a vertical movement starts and ends on the same spot " ) 
  {
    PBoard valid_board = Board::getBoard();

    PBishop piece_on_F7( new Bishop() );
      //F7 on a matrix 0 to 7 is [5][6]

    try {
      // First we make sure the board is clean
      REQUIRE( valid_board->cleanBoard() == Success );

      // Then we check if even if there are no pieces over F7 it should still return Error.
      REQUIRE( valid_board->isClearVertical( 5, 6, 6) == false );

      REQUIRE( valid_board->setPieceAt( 0, 4 , piece_on_F7 ) == Success );

      // After that we check if with a piece over F7 would return Error
      REQUIRE( valid_board->isClearVertical( 5, 6, 6) == false );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return false if a vertical movement starts and ends on the same spot" );
    }
  } // SECTION( " The board returns false if a vertical movement starts and ends on the same spot


  SECTION( " The board returns true or false if a given diagonal path right up is free or not respectively " ) 
  {
    try {
      PBishop piece_on_A6( new Bishop() );
      //A6 on a matrix 0 to 7 is [0][5]
      PBishop piece_on_B7( new Bishop() );
      //B7 on a matrix 0 to 7 is [1][6]

      PBoard clean_board = Board::getBoard();

      clean_board->cleanBoard();

      REQUIRE( clean_board->setPieceAt( 0, 5 , piece_on_A6 ) == Success );

      //Verifying if is clear the path A6 to B8 with just one piece over the board
      REQUIRE( clean_board->isClearDiagonal( 0, 5, 1, 6 ) == true );

      REQUIRE( clean_board->setPieceAt( 1, 6 , piece_on_B7 ) == Success );

      REQUIRE( clean_board->getSquareAt( 1, 6 )->isOccupied() == true );

      //Verifying if is clear the path A6 to B8
      REQUIRE( clean_board->isClearDiagonal( 0, 5, 1, 6 ) == false );

    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return true or false if a given diagonal path right up is free or not respectively" );
    }
  } //SECTION( " The board returns true or false if a given diagonal path right up is free or not respectively" )

  SECTION( " The board return false if a given coordinate pair is not a diagonal " ) 
  {
    try {
      PBoard clean_board = Board::getBoard();

      clean_board->cleanBoard();

      //Verifying if is clear the path D3 to B1 with just one piece over the board
      REQUIRE( clean_board->isClearDiagonal( 5, 4, 2, 5 ) == false );
      
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return false if a given coordinate pair is not a diagonal " );
    }
  } //SECTION( " The board return false if a given coordinate pair is not a diagonal " )


  SECTION( " The board return true or false if a given diagonal path left down is free or not respectively " ) 
  {
    try {
      PBishop piece_on_D3( new Bishop() );
      //D3 on a matrix 0 to 7 is [3][2]

      PBoard clean_board = Board::getBoard();

      clean_board->cleanBoard();

      REQUIRE( clean_board->setPieceAt( 3, 2 , piece_on_D3 ) == Success );

      //Verifying if is clear the path D3 to B1 with just one piece over the board
      REQUIRE( clean_board->isClearDiagonal( 3, 2, 1, 0 ) == true );

      //Verifying if is clear the path F5 to B1
      REQUIRE( clean_board->isClearDiagonal( 5, 4, 2, 1 ) == false );
      
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return true or false if a given diagonal path left down is free or not respectively " );
    }
  } //SECTION( " The board return true or false if a given diagonal path left down is free or not respectively " )

  SECTION( " The board return true or false if a given diagonal path left up or right down is free or not respectively " ) 
  {
    try {
      PBishop piece_on_D6( new Bishop() );
      //D6 on a matrix 0 to 7 is [3][5]

      PBoard clean_board = Board::getBoard();

      clean_board->cleanBoard();

      //Verifying if is clear the path H2 to C7
      REQUIRE( clean_board->isClearDiagonal( 7, 1, 2, 6 ) == true );

      //Verifying if is clear the path B8 to G3
      REQUIRE( clean_board->isClearDiagonal( 1, 7, 6, 2 ) == true );

      REQUIRE( clean_board->setPieceAt( 3, 5 , piece_on_D6 ) == Success );

      //Verifying if is clear the path H2 to C7
      REQUIRE( clean_board->isClearDiagonal( 7, 1, 2, 6 ) == false );

      //Verifying if is clear the path B8 to G3
      REQUIRE( clean_board->isClearDiagonal( 1, 7, 6, 2 ) == false );
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return true or false if a given diagonal path left up or right down is free or not respectively " );
    }
  } //SECTION( " The board return true or false if a given diagonal path left up or right down is free or not respectively )


  SECTION( " The board throws an error if a vertical, horizontal or diagonal movement starts on invalid coordinates " ) 
  {
    try {
      Board::getBoard()->isClearHorizontal( 9, 1, 10 );
    } catch (int throwned_error )
    {
      REQUIRE( "The board does throw an Error when horizontal movement starts on invalid coordinates" );
    }

    try {
      Board::getBoard()->isClearVertical( 9, 1, 5 );
    } catch (int throwned_error )
    {
      REQUIRE( "TThe board does throw an Error when vertical movement starts on invalid coordinates" );
    }

    try {
      Board::getBoard()->isClearDiagonal( 9, 1, 10, 2 );
    } catch (int throwned_error )
    {
      REQUIRE( "The board does throw an Error when diagonal movement starts on invalid coordinates " );
    }
  } // SECTION( " The board throws an error if a vertical movement starts on invalid coordinates " )

  SECTION( " The board return true or false if a given coordinate is on End Row or not respectively " ) 
  {
      PBoard board = Board::getBoard();

      REQUIRE( board->isEndRow( 3, 0 ) == true );
      REQUIRE( board->isEndRow( 3, 2 ) == false );

      REQUIRE( board->isEndRow( 5, 7) == true );
      REQUIRE( board->isEndRow( 5, 6) == false );

  } // SECTION( " The board return true or false if a given coordinate is on End Row or not respectively ) 

  SECTION( " The board return true or false if a given path is free or not respectively " ) 
  {
    try {
      PBishop piece_on_D6( new Bishop() );
      //D6 on a matrix 0 to 7 is [3][5]

      PBoard clean_board = Board::getBoard();

      clean_board->cleanBoard();

      //Verifying if is clear the path H2 to C7
      REQUIRE( clean_board->isClearPath( 7, 1, 2, 6 ) == true );

      //Verifying if is clear the path B8 to G3
      REQUIRE( clean_board->isClearPath( 1, 7, 6, 2 ) == true );

      REQUIRE( clean_board->setPieceAt( 3, 5 , piece_on_D6 ) == Success );

      //Verifying if is clear the path H2 to C7
      REQUIRE( clean_board->isClearPath( 7, 1, 2, 6 ) == false );

      //Verifying if is clear the path B8 to G3
      REQUIRE( clean_board->isClearPath( 1, 7, 6, 2 ) == false );
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "The board doesn't return true or false if a given diagonal path left up or right down is free or not respectively " );
    }
  } //SECTION( " The board return true or false if a given diagonal path left up or right down is free or not respectively )
} // TEST_CASE( "Read", "[board]" )

TEST_CASE( "Update Board", "[board]" ) 
{ 
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:
  //    uint8_t setPieceAt( uint8_t horizontal_coordinate, 
  //            uint8_t vertical_coordinate , PBishop piece_to_be_set );

  SECTION( "A board can change of it's squares pieces " ) 
  {
    try {
      PBishop piece_to_be_set_on_square( new Bishop() );

      REQUIRE( Board::getBoard()->setPieceAt( 2, 3 , piece_to_be_set_on_square ) == Success );
      
    } catch (int throwned_error )
    {
      REQUIRE_FALSE( "Error on changing one of it's squares" );
    }
  } // SECTION( "A board can change of it's squares pieces " )

  SECTION( "A board return an Error if wrong square is given " ) 
  {
      PBishop piece_to_be_set_on_square( new Bishop() );

      REQUIRE( Board::getBoard()->setPieceAt( 9, 3 , piece_to_be_set_on_square ) == Error );
  } // SECTION( "A board return an Error if wrong square is given " )

} // TEST_CASE( "Update", "[board]" ) 

TEST_CASE( "Destroy Board", "[board]" ) 
{
  //! These test case will focus on methods that
  //! updates board
  // These tests will focus on:
  //   ~Board();
  // uint8_t cleanBoard();
  // uint8_t cleanSquareAt(uint8_t horizontal_coordinate, uint8_t vertical_coordinate );

  SECTION( "A board can be deleted and no squares will be left floating" ) 
  { 
    try {
      Board::getBoard().reset();
      REQUIRE_FALSE( Board::getBoard() == nullptr );
      Board::getBoard().reset();
      // Using smart shared pointer I can only guarantee that the reference on square
      // was erased and if there were no other reference to it it'll be succesfully
      // deallocated.
    } catch (int e) {
      REQUIRE_FALSE( "Something wrong ocurred when board was being deleted" );
    }
  }

  SECTION( "The board can be clean of one of it's pieces" ) 
  {
    PBoard board_to_be_clean = Board::getBoard();
    PBishop piece_on_F4( new Bishop );

    board_to_be_clean->setPieceAt( 5, 3, piece_on_F4 );

    REQUIRE_FALSE( board_to_be_clean->getSquareAt( 5, 3 )->getPiece() == nullptr );

    board_to_be_clean->cleanSquareAt( 5, 3 );

    REQUIRE( board_to_be_clean->getSquareAt( 5, 3 )->getPiece() == nullptr );
  } // SECTION( "The board can be clean of one of it's pieces" ) 
    
  SECTION( "The board can be clean of all it's pieces" ) 
  {
    PBoard board_to_be_clean = Board::getBoard();
    PBishop piece_on_F4( new Bishop );
    PBishop piece_on_B7(new Bishop );

    board_to_be_clean->setPieceAt( 5, 3, piece_on_F4 );
    board_to_be_clean->setPieceAt( 1, 6, piece_on_B7 );

    REQUIRE_FALSE( board_to_be_clean->getSquareAt( 5, 3 )->getPiece() == nullptr );
    REQUIRE_FALSE( board_to_be_clean->getSquareAt( 1, 6 )->getPiece() == nullptr );

    board_to_be_clean->cleanBoard();

    REQUIRE( board_to_be_clean->getSquareAt( 5, 3 )->getPiece() == nullptr );
    REQUIRE( board_to_be_clean->getSquareAt( 1, 6 )->getPiece() == nullptr );
  } // SECTION( "The board can be clean of all it's pieces" ) 

} // TEST_CASE( "Destroy", "[board]" ) 