#include "board_square.hpp"

/*! \vertical board_square.cpp
    \brief Module responsible to implement board square behaviors.
*/

//! A constructor that creates a board square.
    /*!
        \Description Creates a new board square.
        Both horizontal or vertical cannot be lower than one or
        greater than the border side size.
        
        \param Two unsigned int bellow KMaximumAllowedCoordinate
        \throw Error if given invalid coordinates
    */
BoardSquare::BoardSquare( uint8_t horizontal_coordinate, uint8_t vertical_coordinate )
{   
    if ( horizontal_coordinate > kMaximumAllowedCoordinate )
    {
        throw (int) Error;
    } //if ( horizontal_coordinate > kMaximumAllowedCoordinate )

    if ( vertical_coordinate > kMaximumAllowedCoordinate )
    {
        throw (int) Error;
    } //if ( vertical_coordinate > kMaximumAllowedCoordinate )

    vertical_ = vertical_coordinate;
    horizontal_ = horizontal_coordinate;
}

//! A destructor that cleans all pointers.
BoardSquare::~BoardSquare()
{
    piece_on_square_.reset();
}

//! A getter to board square horizontal
    /*!
        \return The horizontal coordenate of
        the board square
    */
uint8_t BoardSquare::getHorizontal() const
{
    return horizontal_;
}

//! A getter to board square vertical
    /*!
        \return The vertical coordenate of
        the board square
    */
uint8_t BoardSquare::getVertical() const
{
    return vertical_;
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

