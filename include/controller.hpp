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
  void  savegame(  char (&board)[8][8] );
  char loadboard();
  char showoptions( const char (&board)[8][8] );
  PCodeTable newStandardGame();
  char  newemptyboard();
  static shared_ptr<Controller>  getController();
  void edit();

 private:
  static shared_ptr<Controller> the_controller;
};

#endif
