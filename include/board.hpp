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

typedef shared_ptr<BoardSquare> PBoardSquare;
    // Smart pointer to BoardSquare 
typedef shared_ptr<Piece> PPiece;
    // Smart pointer to Piece

class Board
{
  private:
  static shared_ptr<Board> _board_table; //Points to itself after initialized
  static const unsigned int _size_of_table = 8; //Number of rows and ranks
  PBoardSquare _board_square_matrix[_size_of_table][_size_of_table]; //Matrix to store the board squares

  public:
  Board();
  
  /*! Initializes Board on the first call and returns a pointer to the board
  */
  static shared_ptr<Board> getBoard();

  /*! Returns the board square on given coordinates
  */
  PBoardSquare getBoardSquareAt(unsigned int rank_coordinate, unsigned int file_coordinate );

  unsigned int setPieceAt( unsigned int rank_coordinate, unsigned int file_coordinate , PPiece piece_to_be_set );

  bool isClearHorizontal(unsigned int actual_rank_coordinate, unsigned int actual_file_coordinate, unsigned int future_file_coordinate) const;
  bool isClearVertical(unsigned int actual_rank_coordinate, unsigned int actual_file_coordinate, unsigned int future_rank_coordinate) const;
};

#endif