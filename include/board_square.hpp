#ifndef CATCH_H
#define CATCH_H
#include "catch.hpp"
#endif

//Operations can be Successful or not, every
//method that would simply return void will instead
//return an Error ou Success.
enum OperationStatus {Error, Success};

//The Compare method from the library String
//returns 0 when Equal. To increase readability
//I'll call 0 as Equals.
enum StringEquivalence {Equals};

class BoardSquare {

  public:
  //Methods
  BoardSquare();

  ~BoardSquare();
}