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
char Controller::movepiece( const char (&board)[8][8] )
{


    return 'c';
}

//returns new controller if it's valid or old one if it's not
PCodeTable Controller::validateboard( const char (&code_table_to_be_avalied)[8][8]  ){
    PCodeTable valid_code_table;
    uint8_t size = 8;

    if ( Engine::getEngine()->isValidMove( code_table_to_be_avalied ) )
    {
        valid_code_table = make_unique< unique_ptr<char[]>[] >(size);
        {
            for ( int i = 0; i < size; ++i)
            {
                valid_code_table[i] = make_unique< char[] >(size);

                for (int j = 0; j < size; ++j)
                    valid_code_table[i][j] = code_table_to_be_avalied[8][8];
            }
        }
        
    } else {
        valid_code_table = Engine::getEngine()->returnCodeTable();
    }   

    return valid_code_table;
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