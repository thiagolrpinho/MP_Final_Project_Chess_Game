#ifndef CATCH_H
#define CATCH_H
#include "catch.hpp"
#endif

#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "piece.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "rook.hpp"
#include "pawn.hpp"

#include "stdint.h"
using std::uint8_t;
  //Unsigned int with range [0 to 255]

#include <memory>
using std::shared_ptr; 
using std::unique_ptr;
using std::make_unique;
// Smart pointer that deallocates when no references to it exists

typedef shared_ptr<Piece>   PPiece;
typedef shared_ptr<King>    PKing;
typedef shared_ptr<Queen>   PQueen;
typedef shared_ptr<Bishop>  PBishop;
typedef shared_ptr<Knight>  PKnight;
typedef shared_ptr<Rook>    PRook;
typedef shared_ptr<Pawn>    PPawn;
typedef unique_ptr<unique_ptr<char[]>[]> PCodeTable;


//Operations can be Successful or not, every
//method that would simply return void will instead
//return an Error ou Success.
enum OperationStatus {Error, Success};

//The Compare method from the library String
//returns 0 when Equal. To increase readability
//I'll call 0 as Equals.
enum StringEquivalence {Equals};

//Squares cannot have bigger coordinates than 
//the board side size or lower than 0.
const uint8_t kMaximumAllowedCoordinate = 7;

class Square {
  private:
    //horizontal are lines.
    uint8_t horizontal_;
    //verticals are columns.
    uint8_t vertical_;
    //Squares points to pieces nullptr or a pieace
    shared_ptr<Piece> piece_on_square_;

  public:
  //Methods
  Square( uint8_t horizontal_coordinate, uint8_t vertical_coordinate );
  ~Square();

  //Orientation related methods
  uint8_t getHorizontal() const ;
  uint8_t getVertical() const ;
  
  //Piece related methods
  bool isOccupied() const;
  uint8_t setPiece( shared_ptr<Piece> );
  shared_ptr<Piece> getPiece() const ;
  uint8_t deletePiece();

};

#endif