  /*! engine.hpp
    A engine is a singleton that stores a matrix of engine squares and the size of the
    matrix.
    The engine is responsible to manage all engine squares and it's piece. Only 
    Board can change a engine square state or read it's value.
    To use methods of engine you must call the class Board::getBoard()->NameOfMethod();
  */
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "board.hpp"
#include "player.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;



typedef shared_ptr<Piece> PPiece;
typedef shared_ptr<Player> PPlayer;
    // Smart pointer to Piece

class Engine
{
 private:
  uint8_t table_row_size_;
  PPlayer player1;
  PPlayer player2;
  static PPlayer nextPlayer;

 public:
  uint8_t readCodeTable( const char (&array)[8][8] );
  void printCodeTable( const char (&array)[8][8] );
  PCodeTable returnCodeTable();


  uint8_t new_game();

  // Auxiliary functions
  uint8_t isValidCodeSymbol( char code_symbol );

  uint8_t createPieceAt( uint8_t horizontal_coordinate, 
                uint8_t vertical_coordinate , char code_symbol );

};
#endif