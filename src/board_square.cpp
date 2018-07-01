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
BoardSquare::BoardSquare( uint8_t file_coordinate, uint8_t rank_coordinate )
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
    piece_on_square_.reset();
}

//! A getter to board square rank
    /*!
        \return The horizontal coordenate of
        the board square
    */
uint8_t BoardSquare::getRank()
{
    return rank_;
}

//! A getter to board square file
    /*!
        \return The vertical coordenate of
        the board square
    */
uint8_t BoardSquare::getFile()
{
    return file_;
}

//! A method to test if there's any piece over the square.
    /*!
        \return A boolean which says wether or not
        the piece address pointed by the board square
        is nullptr.
    */
bool BoardSquare::isOccupied()
{
    if ( piece_on_square_ )
        return true;
    else 
        return false;
}

//! Changes the piece over the board square
    /*!
        \param The new piece shared pointer to 
        overwrite the previous piece. The
        new piece should be an already allocated
        valid piece.
        \return Return a Success(Integer 1)
        or Error(Integer 0)
    */
uint8_t BoardSquare::setPiece( shared_ptr<Piece> piece_to_be_set )
{
    try {
        piece_on_square_ = piece_to_be_set;
    } catch (int e) {
        return Error;
    }
    return Success;
}

//! A getter to the piece over the board square
    /*!
        \return Return a shared pointer of 
        the piece on the square.
    */
shared_ptr<Piece> BoardSquare::getPiece()
{
    return piece_on_square_ ;
}

//! Deletes the piece over the board square
    /*!
        \return Return a Success(Integer 1)
        or Error(Integer 0)
    */
uint8_t BoardSquare::deletePiece()
{
    try {
        piece_on_square_.reset();
    } catch (int e) {
        return Error;
    }
    return Success;
}

