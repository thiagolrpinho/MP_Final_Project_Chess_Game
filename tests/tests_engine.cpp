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
  PEngine valid_engine = Engine::getEngine();

  SECTION( "An engine can be successfully created" ) 
  {
    try {
      REQUIRE_FALSE( valid_engine == nullptr );  
    } catch (int e) {
      REQUIRE_FALSE( "The Engine cannot be succesfully created." );
    }
  } // SECTION( "An engine can be successfully created" )


SECTION( "An engine can be read one code symbol and create a piece on the board " ) 
{     
      char game_with_one_kind_of_piece_and_color_code_table[8][8] = 
      {
        { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' }, 
        { 'C' },
        { 'R' }, 
        { 'T' },
        { 'B' },
        { 'Z' },
        { 'z' },
        { 'P' } 
      };
      Board::getBoard()->cleanBoard();

     /*   //game_with_one_kind_of_piece_and_color_code_table
          { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' },
          { 'C' },
          { 'R' }, 
          { 'T' },
          { 'B' },
          { 'Z' },
          { 'z' },
          { 'P' } 
      */

     
      // 'p' is a valid code table, so it should create a pawn on A7 and return Success
      REQUIRE( valid_engine->createPieceAt( 0, 0, 'p' ) == Success );
      REQUIRE( ( (Pawn*)( Board::getBoard()->getPieceAt( 0, 0 ).get() ) )->isPawn == true );

      REQUIRE( valid_engine->createPieceAt( 4, 0, 'B' ) == Success );
      REQUIRE( ( (Bishop*)( Board::getBoard()->getPieceAt( 4, 0 ).get() ) )->isBishop == true );


  } // SECTION( An engine can be read one code symbol and create a piece on the board " )

  SECTION( "An engine can be read one code symbol and create a piece on the board with the right color " ) 
  {     
    char game_with_one_kind_of_piece_and_color_code_table[8][8] = 
    {
      { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' }, 
      { 'C' },
      { 'R' }, 
      { 'T' },
      { 'B' },
      { 'Z' },
      { 'z' },
      { 'P' } 
    };
    Board::getBoard()->cleanBoard();

    /*   //game_with_one_kind_of_piece_and_color_code_table
        { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' },
        { 'C' },
        { 'R' }, 
        { 'T' },
        { 'B' },
        { 'Z' },
        { 'z' },
        { 'P' } 
    */

    
    // 'p' is a valid code table, so it should create a pawn on A7 and return Success
    REQUIRE( valid_engine->createPieceAt( 0, 0, 'p' ) == Success );
    REQUIRE( ( (Pawn*)( Board::getBoard()->getPieceAt( 0, 0 ).get() ) )->isPawn == true );
    REQUIRE( ( (Pawn*)( Board::getBoard()->getPieceAt( 0, 0 ).get() ) )->isWhite == true );

    // 'P' is a valid code table, so it should create a black pawn on A0 
    REQUIRE( valid_engine->createPieceAt( 7, 0, 'P' ) == Success );
    REQUIRE( ( (Pawn*)( Board::getBoard()->getPieceAt( 7, 0 ).get() ) )->isPawn == true );
    REQUIRE( ( (Pawn*)( Board::getBoard()->getPieceAt( 7, 0 ).get() ) )->isWhite == false );

  } // SECTION( "An engine can be read one code symbol and create a piece on the board with the right color "  )

} // TEST_CASE( "Create", "[Engine]" )

TEST_CASE( "Read Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! reads objects within Engine class
  // These tests will focus on:./
  PEngine valid_engine = Engine::getEngine();
  const char initial_game_code_table[8][8] = 
  {
    { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    { }, //These will be filled with 0
    { },
    { },
    { },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
  };

  const char wrong_game_code_table[8][8] = 
  {
    { 'T', 'C', 'B', 'R', 'Y', 'B', 'C', 'T'},
    { 'P', 'X', 'P', 'P', 'P', 'P', 'P', 'P'},
    { }, //These will be filled with 0
    { },
    { },
    { },
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
  };

  const char game_with_one_kind_of_piece_code_table[8][8] = 
  {
    { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' }, 
    { },
    { }, //These will be filled with 0
    { },
    { },
    { },
    { },
    { 0,0,0,0,'z' } //Matrix[5][7] = king
  };

  SECTION( "An engine can be read one char code table and return Success if correct" ) 
  {
      REQUIRE( valid_engine->readCodeTable(initial_game_code_table) == Success );
  } // SECTION( "An engine can be read one char code table and return Error if not correct" )

  SECTION( "An engine can be read one char code table and return Error if not correct" ) 
  {
      REQUIRE( valid_engine->readCodeTable(wrong_game_code_table) == Error );
  } // SECTION( "An engine can be read one char code table and return Error if not correct" )

  SECTION( "An engine can be read one char code table and add pieces to it" ) 
  {
      Board::getBoard()->cleanBoard();
      REQUIRE( valid_engine->readCodeTable(initial_game_code_table) == Success );
      REQUIRE( Board::getBoard()->getSquareAt( 1, 0 )->isOccupied() == true );
  } // SECTION( "An engine can be read one char code table and add pieces to it" )

  SECTION( "An engine can be read one char code table and add a specific piece to it" ) 
  {
      PKing   test_king_piece( new King() );
      PQueen  test_queen_piece( new Queen() );
      PBishop test_bishop_piece( new Bishop() );
      PKnight test_knight_piece( new Knight() );
      PRook   test_rook_piece( new Rook() );
      PPawn   test_pawn_piece( new Pawn() );

      Board::getBoard()->cleanBoard();
      REQUIRE( valid_engine->readCodeTable( game_with_one_kind_of_piece_code_table ) == Success );
      REQUIRE( Board::getBoard()->getSquareAt( 4, 7 )->isOccupied() == true );

      /*
          { 'p', 'c', 'r', 't', 'b', 'z', 'Z', 'C' },
          { },
          { }, 
          { },
          { },
          { },
          { },
          { 0,0,0,0,'z' }
      */
      //Now we assure that the piece set was specific a king
      REQUIRE( ((King*)(Board::getBoard()->getPieceAt( 4, 7 ).get()))->isKing == true );

      //Now we assure that the piece on A1 set was specific a White Pawn
      REQUIRE( ((Pawn*)(Board::getBoard()->getPieceAt( 0, 0 ).get()))->isPawn == true );
      REQUIRE( ((Pawn*)(Board::getBoard()->getPieceAt( 0, 0 ).get()))->isWhite == true );

      //Now we assure that the piece on B1 set was specific a White Knight
      REQUIRE( ((Knight*)(Board::getBoard()->getPieceAt( 1, 0 ).get()))->isKnight == true );
      REQUIRE( ((Knight*)(Board::getBoard()->getPieceAt( 1, 0 ).get()))->isWhite == true );

      //Now we assure that the piece on C1 set was specific a White Queen
      REQUIRE( ((Queen*)(Board::getBoard()->getPieceAt( 2, 0 ).get()))->isQueen == true );
      REQUIRE( ((Queen*)(Board::getBoard()->getPieceAt( 2, 0 ).get()))->isWhite == true );

      //Now we assure that the piece set on D1 was specific a White Rook
      REQUIRE( ((Rook*)(Board::getBoard()->getPieceAt( 3, 0 ).get()))->isRook == true );
      REQUIRE( ((Rook*)(Board::getBoard()->getPieceAt( 3, 0 ).get()))->isWhite == true );

      //Now we assure that the piece set on E1 was specific a White Bishop
      REQUIRE( ((Bishop*)(Board::getBoard()->getPieceAt( 4, 0 ).get()))->isBishop == true );
      REQUIRE( ((Bishop*)(Board::getBoard()->getPieceAt( 4, 0 ).get()))->isWhite == true );

      //Now we assure that the piece set on F1 was specific a White King
      REQUIRE( ((King*)(Board::getBoard()->getPieceAt( 5, 0 ).get()))->isKing == true );
      REQUIRE( ((King*)(Board::getBoard()->getPieceAt( 5, 0 ).get()))->isWhite == true );

      //Now we assure that the piece set on G1 was specific a Black King
      REQUIRE( ((King*)(Board::getBoard()->getPieceAt( 6, 0 ).get()))->isKing == true );
      REQUIRE( ((King*)(Board::getBoard()->getPieceAt( 6, 0 ).get()))->isWhite == false );

      //Now we assure that the piece set on H1 was specific a Black Knight
      REQUIRE( ((Knight*)(Board::getBoard()->getPieceAt( 7, 0 ).get()))->isKnight == true );
      REQUIRE( ((Knight*)(Board::getBoard()->getPieceAt( 7, 0 ).get()))->isWhite == false );
      
      
  } // SECTION( "An engine can be read one char code table and add a specific piece to it" )
  
  SECTION( "An engine can be read one table code and know if its code is valid " ) 
  {
      Board::getBoard()->cleanBoard();

      /*
         // wrong_game_code_table
          { 'T', 'C', 'B', 'R', 'Y', 'B', 'C', 'T'},
          { 'P', 'X', 'P', 'P', 'P', 'P', 'P', 'P'},
          { }, //These will be filled with 0
          { },
          { },
          { },
          { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
          { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      */
      // T is a valid code table, so it should return Success
      REQUIRE( valid_engine->isValidCodeSymbol('T') == Success );
      
      // X is not a valid code table, so it should return Error
      REQUIRE( valid_engine->isValidCodeSymbol('X') == Error );

  } // SECTION( "An engine can be read one table code and know if its code is valid " )

  SECTION( "An engine can be return a code table" ) 
  {
      PCodeTable returned_code_table = nullptr;

      Board::getBoard()->cleanBoard();

      REQUIRE( valid_engine->readCodeTable(initial_game_code_table) == Success );

      returned_code_table = valid_engine->returnCodeTable();

      REQUIRE_FALSE( returned_code_table == nullptr ); 

      /*
       {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { }, //These will be filled with 0
        { },
        { },
        { },
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
      };
      */
      //Now let's check if it's returning the same code table
      for( uint8_t i = 0; i < 8; i++ )
      {
        for( uint8_t j = 0; j < 8; j++ )
        {
          REQUIRE( returned_code_table[i][j] == initial_game_code_table[i][j] );
        }
      }
      
  } // SECTION( "An engine can be return a code table" )

  SECTION( "An engine can say if a same code table is a valid state change" ) 
  {
    Board::getBoard()->cleanBoard();
    valid_engine->readCodeTable( initial_game_code_table);
    // As it is the same valid code table, it should return true
    REQUIRE( valid_engine->isValidMove( initial_game_code_table ) == true );

  } // An engine can say if a same code table is a valid state change"

  SECTION( "An engine can say if a new invalid move table is a valid state change" ) 
  {
    Board::getBoard()->cleanBoard();
    valid_engine->readCodeTable( initial_game_code_table);

    const char next_invalid_missing_one_piece_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  0, 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn missing without a reason
      { },
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidMove( next_invalid_missing_one_piece_code_table ) == false );

    const char next_invalid_wrong_pieces_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'X', 'P', 'P', 'P', 'P'},
      { },  // Invalid symbol
      { },
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidMove( next_invalid_wrong_pieces_code_table ) == false );

    const char diagonal_move_invalid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 0,  'P', 'P', 'P', 'P', 'P', 'P'},
      { 'P'},  // Pawn jump to the diagonal
      { },
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidMove( diagonal_move_invalid_code_table ) == false );

    const char horse_wrong_jump_invalid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Horse jump invalid
      { },
      { },
      { 0, 'c'},
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 'z', 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidMove( horse_wrong_jump_invalid_code_table ) == false );

    const char another_horse_wrong_jump_invalid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Horse jump invalid
      { },
      { },
      { 0, 0, 0, 'c'},
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 'z', 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidMove( another_horse_wrong_jump_invalid_code_table ) == false );

    const char pawn_valid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 0,  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  
      { },
      { },
      { 'p' },
      { 0, 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'p', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    //Can only double jump when not moved
    const char pawn_invalid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 0,  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  
      { 'p'},
      { },
      { },
      { 0, 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'p', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    Board::getBoard()->cleanBoard();
    valid_engine->readCodeTable( pawn_valid_code_table);
    REQUIRE( valid_engine->isValidMove( pawn_invalid_code_table ) == false ); 

  } // "An engine can say if a new invalid move table is a valid state change"

  SECTION( "An engine can say if a new valid move table is a valid state change" ) 
  {
    Board::getBoard()->cleanBoard();
    const char next_valid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 0, 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { 'P' },  // Pawn move one square
      { },
      { },
      { },
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };

    valid_engine->readCodeTable( initial_game_code_table);
    // As it is the same valid code table, it should return true
    CHECK( valid_engine->isValidMove( next_valid_code_table ) == true );

    const char another_next_valid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      { },
      { },
      { 'p' },
      { 0, 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    CHECK( valid_engine->isValidMove( another_next_valid_code_table ) == true );

    const char pawn_jump_next_valid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      { },
      { 'p' },
      { },
      { 0, 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    CHECK( valid_engine->isValidMove( pawn_jump_next_valid_code_table ) == true );


    const char knight_jump_next_valid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      { },
      { },
      { 0, 0, 'c',},
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 'z', 'b', 'c', 't'}
    };
    CHECK( valid_engine->isValidMove( knight_jump_next_valid_code_table ) == true );

    Board::getBoard()->cleanBoard();
    const char valid_pawn_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 0, 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      {'P'},
      { 0, 'p'},
      { },
      { 'p', 0, 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };

    valid_engine->readCodeTable( valid_pawn_code_table);

    const char black_pawn_eats_black_pawn_next_valid_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Black pawn
      { },
      { 0, 'P' },
      { },
      { 'p', 0, 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidMove( black_pawn_eats_black_pawn_next_valid_code_table ) == true );

  } // "An engine can say if a new invalid move table is a valid state change"

  SECTION( "An engine can be read one edited table code and know if its code is valid " ) 
  {
    const char valid_edited_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      { },
      { },
      { 0, 0, 'c',},
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 'z', 'b', 'c', 't'}
    };

    REQUIRE( valid_engine->isValidEditedTable( valid_edited_code_table ) == Success );

    const char invalid_edited_code_table[8][8] = 
    {
      { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
      { 'P', 'P',  'P', 'P', 'P', 'P', 'P', 'P'},
      { },  // Pawn move one square
      { },
      { },
      { 0, 0, 'c',},
      { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
      { 't', 0, 'b', 'r', 0, 'b', 'c', 't'}
    };
    REQUIRE( valid_engine->isValidEditedTable( invalid_edited_code_table ) == Error );

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
    REQUIRE( valid_engine->isValidEditedTable( invalid_two_queen_edited_code_table ) == Error );

  } // "An engine can be read one edited table code and know if its code is valid "
} //TEST_CASE( "Read Engine", "[Engine]" ) 

TEST_CASE( "Update Engine", "[Engine]" ) 
{ 
  //! These test case will focus on methods that
  //! updates Engine
  // These tests will focus on:
  PEngine valid_engine = Engine::getEngine();


  SECTION( "An engine can start a new game" ) 
  {
      REQUIRE( valid_engine->new_game() == Success );

      REQUIRE_FALSE( valid_engine->getNextPlayer() == nullptr );
      REQUIRE_FALSE( valid_engine->getNextPlayer()->isWhite() );
      REQUIRE_FALSE( valid_engine->opponentOf(valid_engine->getNextPlayer() )->isWhite() );
  } // SECTION( "An engine can be return a code table" )
  
} // TEST_CASE( "Update", "[Engine]" ) 

TEST_CASE( "Destroy Engine", "[Engine]" ) 
{
  //! These test case will focus on methods that
  //! updates Engine
  // These tests will focus on:

} // TEST_CASE( "Destroy", "[Engine]" ) 