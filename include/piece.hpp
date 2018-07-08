#ifndef PIECE_HPP
#define PIECE_HPP
class Piece 
{ 

  public:
  bool isWhite = true;

  Piece();
  Piece( char is_being_created_white );
  
  void setBlack();
  char getCodeSymbol()
  {
    return 0;
  };
};

#endif