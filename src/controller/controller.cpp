#include "controller.hpp"

shared_ptr<Controller>  Controller::getController()
{
    //If there's no controller, then create one.
    if( the_controller == nullptr )
    {
        try {
            the_controller.reset( new Controller() );
            //Reset controller table to new controller
        } catch ( int throwned_error) {
            // If there was a failure creating controller
            throw Error;
        }
    }

    return the_controller;
}
//calls game engine and receives new board
PCodeTable Controller::movePiece( const char (&board)[8][8] )
{
    if( Engine::getEngine()->isValidMove(board) )
    {
        if ( Engine::getEngine()->readCodeTable(board) == Error )
            throw (int) Error;
    }

    return Engine::getEngine()->returnCodeTable();
}

//returns new controller if it's valid or old one if it's not
bool Controller::validateBoard( const char (&board_to_be_avalied)[8][8]  )
{
    return Engine::getEngine()->isValidEditedTable( board_to_be_avalied );
}

//calls ai and receives and new controller with it's move
char  aimove( const char (&controller)[8][8]  ){

    return 0;
}

//calls savegame function
void  savegame( char (*controller)[8][8]  ){
    salvarTab(controller);

}
//calls function to load controller returns loaded controller
void loadboard( char (*controller)[8][8]){
    carregaTab(controller);

}



//calls function to edit empty controller returns edited controller
void edit(char (&controller)[8][8]) {
    editar(&controller);

}


//calls function to show options for moves
/*
char showoptions( const char (&controller)[8][8]  ){

    return controller;
}
*/
//returns new standard controller
PCodeTable newStandardGame(){
    Engine::getEngine()->returnCodeTable();

    return Engine::getEngine()->returnCodeTable();;
}


shared_ptr<Controller> Controller::the_controller = nullptr;
