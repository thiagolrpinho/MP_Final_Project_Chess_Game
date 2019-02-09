#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "salvar.hpp"
#include "engine.hpp"

class Controller 
{
  
 public:
  PCodeTable movePiece( const char (&board)[8][8] );
  bool validateBoard( const char (&board_to_be_avalied)[8][8]  );
  char  aimove( const char (&board)[8][8] );
  void  savegame( const char (&board)[8][8] );
  char loadboard();
  char showoptions( const char (&board)[8][8] );
  char newstandardgame();
  char  newemptyboard();
  static shared_ptr<Controller>  getController();

  bool tryTurn( const char (&board)[8][8] );


 private:
  static shared_ptr<Controller> the_controller;
};

#endif