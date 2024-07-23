#include <iostream>
#include <regex>
#include <sstream>
#include <cstdint>
#include "game.h"
#include "board.h"

using namespace std;

errorCodes_e gameResult = OK;

int main()
{
    Board B1;
    while (gameResult != END) {
        gameResult = game(B1);
    };

    return 0;
}
