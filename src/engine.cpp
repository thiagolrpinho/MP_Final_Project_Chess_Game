#include "engine.hpp"

uint8_t Engine::readCodeTable(char (&array)[8][8])
{
    std::cout << __func__ << std::endl;
    for (size_t i = 0; i < 8; ++i)
    {
        std::cout << i << ": ";
        for (size_t j = 0; j < 8; ++j)
            std::cout << array[i][j] << '\t';
        std::cout << std::endl;
    }
    return Error;
}