
#ifndef BOARD_HPP
#define BOARD_HPP
#include "board_square.hpp"

typedef shared_ptr<BoardSquare> PBoardSquare;
// Smart pointer to BoardSquare

class Board
{
  private:
  static shared_ptr<Board> _board_table;
  static const unsigned int _size_of_table = 8;
  PBoardSquare _board_square_matrix[_size_of_table][_size_of_table];

  public:
  Board();
  static shared_ptr<Board> getBoard();
};

#endif