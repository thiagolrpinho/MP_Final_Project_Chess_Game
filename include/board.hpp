
#ifndef BOARD_HPP
#define BOARD_HPP
#include "board_square.hpp"

class Board
{
  private:
  static Board* _board_table = nullptr;
  static const unsigned char _size_of_table = 8;
  BoardSquare*** _board_square_matrix_;
  Board();
  
  public:
  Board* getBoard();
};

#endif