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

typedef shared_ptr<BoardSquare> PBoardSquare;
    // Smart pointer to BoardSquare 
typedef shared_ptr<Piece> PPiece;
    // Smart pointer to Piece

class Engine
{
};
#endif