
#ifndef BOARD_HPP
#define BOARD_HPP
#include "board_square.hpp"

class Board
{
  private:
  static Board* _board_table;
  static const unsigned char _size_of_table = 8;
  BoardSquare*** _board_square_matrix;
  Board();
  
  public:
  static Board* getBoard();
};

#endif