#include "board_square.hpp"

/*! \file board_square.cpp
    \brief Module responsible to implement board square behaviors.
*/

//! A constructor that creates a board square.
    /*!
        \Description Creates a new board square.
    */
BoardSquare::BoardSquare( int file_coordinate, int rank_coordinate )
{
    _file = file_coordinate;
    _rank = rank_coordinate;
}

int BoardSquare::getRank()
{
    return 0;
}

int BoardSquare::getFile()
{
    return 0;
}