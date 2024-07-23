#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "board.h"

enum errorCodes {
    OK = 0,
    NOK = 1,
    END = 10
};

enum gameStatus {
    NEW,
    IN_PROGRESS,
    SOLVED,
    ERROR = 10
};

errorCodes game(Board &board);
void clearConsole();
void printWelcomeMsg();
void printMenu(gameStatus status);
gameStatus menuAPI(int nr, Board &b);

#endif // GAME_H_INCLUDED
