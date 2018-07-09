#include <memory>
#include "../Salvar.cpp"
#include "../engine.cpp"

using std::unique_ptr;
typedef unique_ptr<char*> Matrix;


char movepiece(char board[8][8]);
bool validateboard(char board[8][8]);
char  aimove(char board[8][8]);
void  savegame(char board[8][8]);
char loadboard();
char showoptions(char board[8][8]);
char newstandardgame();
char  newemptyboard();
