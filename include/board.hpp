  /*! board.hpp
    A board is a singleton that stores a matrix of board squares and the size of the
    matrix.
    The board is responsible to manage all board squares and it's piece. Only 
    Board can change a board square state or read it's value.
    To use methods of board you must call the class Board::getBoard()->NameOfMethod();
  */
#ifndef BOARD_HPP
#define BOARD_HPP
#include "board_square.hpp"
#include <cmath>

using std::abs;
  // For absolute value of coordinates

typedef shared_ptr<BoardSquare> PBoardSquare;
    // Smart pointer to BoardSquare 
typedef shared_ptr<Piece> PPiece;
    // Smart pointer to Piece

class Board
{
  private:
  static shared_ptr<Board> board_table_; //Points to itself after initialized
  static const uint8_t size_of_table_ = kMaximumAllowedCoordinate + 1; 
        // Number of rows and horizontals 
  PBoardSquare squares_[size_of_table_][size_of_table_]; //Matrix to store the board squares

  public:
  Board();
  ~Board();
  
  /*! Initializes Board on the first call and returns a pointer to the board
  */
  static shared_ptr<Board> getBoard();

  uint8_t cleanBoard();

  uint8_t cleanBoardSquareAt(uint8_t horizontal_coordinate, uint8_t vertical_coordinate );

  /*! Returns the board square on given coordinates
  */
  PBoardSquare getBoardSquareAt(uint8_t horizontal_coordinate, uint8_t vertical_coordinate );

  uint8_t setPieceAt( uint8_t horizontal_coordinate, 
                uint8_t vertical_coordinate , PPiece piece_to_be_set );

  bool isClearHorizontal(uint8_t actual_horizontal_coordinate, 
              uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate) const;

  bool isClearVertical(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_vertical_coordinate) const;

  bool isClearDiagonal(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate, uint8_t future_horizontal_coordinate,
               uint8_t future_vertical_coordinate ) const;
               
  bool isEndRow(uint8_t actual_horizontal_coordinate,
               uint8_t actual_vertical_coordinate) const;
};

#endif