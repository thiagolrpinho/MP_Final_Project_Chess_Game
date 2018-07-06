#include "engine.hpp"

uint8_t Engine::readCodeTable( char (&array)[8][8] )
{   
    PPiece a_piece( new Piece() );
    for( size_t horizontal = 0; horizontal < 8; ++horizontal )
    {
        for(size_t vertical = 0; vertical < 8; ++vertical )
        {
            if( Board::getBoard()->setPieceAt(horizontal, vertical, a_piece) == Error )
            return Error;
        }
    }
    return Success;
}

void Engine::printCodeTable( char (&array)[8][8] )
{
        std::cout << __func__ << std::endl;
    for (size_t i = 0; i < 8; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < 8; ++j)
            std::cout << array[i][j] << '\t';
        std::cout << std::endl;
    }
}