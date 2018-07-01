#ifndef CATCH_H
#define CATCH_H
#include "catch.hpp"
#endif

#ifndef BOARD_SQUARE_HPP
#define BOARD_SQUARE_HPP
#include "piece.hpp"

#include "stdint.h"
using std::uint8_t;
  //Unsigned int with range [0 to 255]

#include <memory>
using std::shared_ptr; 
// Smart pointer that deallocates when no references to it exists

//Operations can be Successful or not, every
//method that would simply return void will instead
//return an Error ou Success.
enum OperationStatus {Error, Success};

//The Compare method from the library String
//returns 0 when Equal. To increase readability
//I'll call 0 as Equals.
enum StringEquivalence {Equals};

//BoardSquares cannot have bigger coordinates than 
//the board side size or lower than 0.
const uint8_t kMaximumAllowedCoordinate = 7;

class BoardSquare {
  private:
    //Rank are lines.
    uint8_t rank_;
    //Files are columns.
    uint8_t file_;
    //Squares points to pieces nullptr or a pieace
    shared_ptr<Piece> piece_on_square_ = nullptr;

  public:
  //Methods
  BoardSquare( uint8_t file_coordinate, uint8_t rank_coordinate );
  ~BoardSquare();

  //Orientation related methods
  uint8_t getRank();
  uint8_t getFile();
  
  //Piece related methods
  bool isOccupied();
  uint8_t setPiece( shared_ptr<Piece> );
  shared_ptr<Piece> getPiece();
  uint8_t deletePiece();

};

#endif