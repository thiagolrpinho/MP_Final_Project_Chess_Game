#ifndef PIECE_HPP
#define PIECE_HPP
class Piece 
{ 
  private:
  char code_symbol_;

  public:
  bool isWhite = true;

  Piece();
  Piece( char is_being_created_white );
  
  void setBlack();
  void setCodeSymbol();
  char getCodeSymbol();
};

#endif