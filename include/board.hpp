
#ifndef BOARD_HPP
#define BOARD_HPP
#include "board_square.hpp"

class Board
{
  private:
  static Board* _board_table;
  static const unsigned int _size_of_table = 8;
  BoardSquare* _board_square_matrix[_size_of_table][_size_of_table];

  public:
  Board();
  static Board* getBoard();
};

#endif