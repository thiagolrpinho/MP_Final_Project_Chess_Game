#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN   //< This tells Catch to provide a main() - only do this in one cpp file
#endif  // CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/controller/controller.cpp"


SECTION( "Creating and testing matrix" )
{
    try {
        Matrix board = new char*[8];
        for (int i = 0; i < 8; ++i)
        board[i] = new char[i];


        REQUIRE_FALSE( board == nullptr );
    } catch (int e) {
        REQUIRE_FALSE( "The Board cannot be succesfully creat." );
    }

    REQUIRE(movepiece(board)!=nullptr);
    REQUIRE(savegame(board)==1);
    REQUIRE(loadboard(board!=nullptr);
    REQUIRE(showoptions(board)!=nullptr);
    REQUIRE(newstandardgame(board)!=nullptr);
    REQUIRE(newemptyboard(board)!=nullptr);
    REQUIRE(movepiecelocation(board)!=nullptr);
}
