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

//! A destructor that cleans all pointers.
BoardSquare::~BoardSquare()
{
    free (piece_on_square_);
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

bool BoardSquare::isOccupied()
{
    if ( piece_on_square_ )
        return true;
    else 
        return false;
}

unsigned short int BoardSquare::setPiece(Piece * piece_to_be_set )
{
    try {
        piece_on_square_ = piece_to_be_set;
    } catch (int e) {
        return Error;
    }
    return Success;
}

Piece * BoardSquare::getPiece(){
    return piece_on_square_ ;
}

