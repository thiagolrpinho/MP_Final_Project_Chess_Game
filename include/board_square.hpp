#ifndef CATCH_H
#define CATCH_H
#include "catch.hpp"
#endif

#ifndef BOARD_SQUARE_HPP
#define BOARD_SQUARE_HPP

//Operations can be Successful or not, every
//method that would simply return void will instead
//return an Error ou Success.
enum OperationStatus {Error, Success};

//The Compare method from the library String
//returns 0 when Equal. To increase readability
//I'll call 0 as Equals.
enum StringEquivalence {Equals};

class BoardSquare {
  private:
    //Rank are lines.
    int rank_;
    //Files are columns.
    int file_;

  public:
  //Methods
  BoardSquare( int file_coordinate, int rank_coordinate );

  ~BoardSquare();

  int getRank();
  int getFile();

};

#endif