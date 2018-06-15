#include "board_square.hpp"

/*! \file board_square.cpp
    \brief Module responsible to implement board square behaviors.
*/

//! A constructor that creates a board square.
    /*!
        \Description Creates a new board square.
        Both rank or file cannot be lower than 1 or
        greater than 8.
        
        \param Two Int between (1 - 8)
    */
BoardSquare::BoardSquare( int file_coordinate, int rank_coordinate )
{   
    if ( rank_coordinate < 1 || rank_coordinate > 8)
    {
        throw (int) Error;
    } //if ( rank_coordinate < 1 || rank_coordinate > 8)

    

    file_ = file_coordinate;
    rank_ = rank_coordinate;
}

//! A getter to board square rank
    /*!
        \return The horizontal coordenate of
        the board square
    */
int BoardSquare::getRank()
{
    return rank_;
}

//! A getter to board square file
    /*!
        \return The vertical coordenate of
        the board square
    */
int BoardSquare::getFile()
{
    return file_;
}