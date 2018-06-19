#ifndef CATCH_H
#define CATCH_H
#include "catch.hpp"
#endif

#ifndef BOARD_SQUARE_HPP
#define BOARD_SQUARE_HPP
#include "piece.hpp"


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
//the board side size or lower than 1.
const unsigned short int kMaximumAllowedCoordinate = 8;
const unsigned short int kMinimunAllowedCoordinate = 1;

class BoardSquare {
  private:
    //Rank are lines.
    unsigned short int rank_;
    //Files are columns.
    unsigned short int file_;
    //Squares points to pieces nullptr or a pieace
    shared_ptr<Piece> piece_on_square_ = nullptr;

  public:
  //Methods
  BoardSquare( unsigned short int file_coordinate, unsigned short int rank_coordinate );
  ~BoardSquare();

  //Orientation related methods
  unsigned short int getRank();
  unsigned short int getFile();
  
  //Piece related methods
  bool isOccupied();
  unsigned short int setPiece( shared_ptr<Piece> );
  shared_ptr<Piece> getPiece();
  unsigned short int deletePiece();

};

#endif