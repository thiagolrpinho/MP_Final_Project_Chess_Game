#include "board_square.hpp"

/*! \file board_square.cpp
    \brief Module responsible to implement board square behaviors.
*/

//! A constructor that creates a board square.
    /*!
        \Description Creates a new board square.
        Both rank or file cannot be lower than one or
        greater than the border side size.
        
        \param Two Int between (kMinimunAllowedCoordinate and kMaximumAllowedCoordinate)
    */
BoardSquare::BoardSquare( unsigned short int file_coordinate, unsigned short int rank_coordinate )
{   
    if ( rank_coordinate < kMinimunAllowedCoordinate || rank_coordinate > kMaximumAllowedCoordinate)
    {
        throw (int) Error;
    } //if ( rank_coordinate < kMinimunAllowedCoordinate || rank_coordinate > kMaximumAllowedCoordinate)

    if ( file_coordinate < kMinimunAllowedCoordinate || file_coordinate > kMaximumAllowedCoordinate)
    {
        throw (int) Error;
    } //if ( file_coordinate < kMinimunAllowedCoordinate || file_coordinate > kMaximumAllowedCoordinate)

    file_ = file_coordinate;
    rank_ = rank_coordinate;
}

//! A getter to board square rank
    /*!
        \return The horizontal coordenate of
        the board square
    */
unsigned short int BoardSquare::getRank()
{
    return rank_;
}

//! A getter to board square file
    /*!
        \return The vertical coordenate of
        the board square
    */
unsigned short int BoardSquare::getFile()
{
    return file_;
}

Piece * BoardSquare::getPiece(){
    return piece_on_square_ ;
}