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
    file_ = file_coordinate;
    rank_ = rank_coordinate;
}

int BoardSquare::getRank()
{
    return rank_;
}

int BoardSquare::getFile()
{
    return file_;
}