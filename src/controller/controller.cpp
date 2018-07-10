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
char Controller::movepiece( const char (&board)[8][8] ){


    return 'c';
}

//returns new controller if it's valid or old one if it's not
bool Controller::validateboard( const char (&controller)[8][8]  ){

    return false;
}
/* 
//calls ai and receives and new controller with it's move
char  aimove( const char (&controller)[8][8]  ){

    return 0
}

//calls savegame function
void  savegame( const char (&controller)[8][8]  ){
    salvarTab(&controller);

}
//calls function to load controller returns loaded controller
char loadboard(){
    char controller[8][8] =
    {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };
    carregaTab(&controller);

    return controller;

}
//calls function to edit empty controller returns edited controller
char editboard() {
    char controller[8][8] =
    {
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'}
    };
    editar(&controller);

    return controller;
}


//calls function to show options for moves
char showoptions( const char (&controller)[8][8]  ){

    return controller;
}

//returns new standard controller
char newstandardgame(){
    char controller[8][8] =
    {
        { 'T', 'C', 'B', 'R', 'Z', 'B', 'C', 'T'},
        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { '0', '0', '0', '0', '0', '0', '0', '0'},
        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        { 't', 'c', 'b', 'r', 'z', 'b', 'c', 't'}
    };

    return controller;
}

//calls funtion that creates a new empty controller and asks for the right pieces
char  newemptyboard(){
    //char controller[8][8]=editar();

    return controller;
} */

shared_ptr<Controller> Controller::the_controller = nullptr;