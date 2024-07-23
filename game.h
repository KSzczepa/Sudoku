#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "board.h"
#include "types.h"

gameResult_e game(Board &board);
void clearConsole();
void printWelcomeMsg();
level_e handleDifficultyLvl();
void printMenu(gameStatus_e status);
gameStatus_e menuAPI(int nr, Board &b);

#endif // GAME_H_INCLUDED
