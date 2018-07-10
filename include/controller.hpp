#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include "salvar.hpp"
#include "engine.hpp"


char movepiece( const char (&board)[8][8] );
bool validateboard( const char (&board)[8][8] );
char  aimove( const char (&board)[8][8] );
void  savegame( const char (&board)[8][8] );
char loadboard();
char showoptions( const char (&board)[8][8] );
char newstandardgame();
char  newemptyboard();

#endif