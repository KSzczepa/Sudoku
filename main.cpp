#include <iostream>
#include "game.h"
#include "board.h"

gameResult_e gameResult = OK;

int main()
{
    Board B1;
    while (gameResult != END) {
        gameResult = game(B1);
    };

    return 0;
}
