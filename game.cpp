#include "game.h"
#include "board.h"
#include <iostream>
#include <cstdlib>

errorCodes game(Board &board) {
    errorCodes res = OK;
    static gameStatus status = NEW;
    int nr = 0;

    clearConsole();
    printWelcomeMsg();

    board.print();

    printMenu(status);
    std::cin >> nr;

    if (nr == 0) {
        return END;
    }

    do {
        status = menuAPI(nr, board);
    } while (status == ERROR);

    return res;
};

void clearConsole() {
    system("cls");
};

void printWelcomeMsg() {
    std::cout << "===========================================" << std::endl;
    std::cout << "============ Welcome to Sudoku! ===========" << std::endl;
    std::cout << "===========================================" << std::endl;
};

void printMenu(gameStatus status) {
    if (status == NEW) {
        std::cout << " 1 - enter number" << std::endl;
        std::cout << " 2 - show result" << std::endl;
        std::cout << " 0 - end game" << std::endl;
    }
    else if (status == IN_PROGRESS) {
        std::cout << " 1 - enter number" << std::endl;
        std::cout << " 2 - show result" << std::endl;
        std::cout << " 3 - start again" << std::endl;
        std::cout << " 0 - end game" << std::endl;
    }
    else {
        std::cout << " 3 - start again" << std::endl;
        std::cout << " 0 - end game" << std::endl;
    }

};

gameStatus menuAPI(int nr, Board &b) {
    gameStatus status = ERROR;
    switch (nr) {
        case 1: {
            int row, col, val;
            bool res;
            std::cout << "Enter  row col and value ";
            std::cin >> row >> col >> val;
            res = b.add(row, col, val);
            status = res ? IN_PROGRESS : ERROR;
        }; break;
        case 2: {
            b.clearBoard();
            b.solveSudoku();
            status = SOLVED;
        }; break;
        case 3: {
            b.clearBoard();
            status = NEW;
        }; break;
        default: {
            std::cout << "Enter another number!" << std::endl;
        }; break;
    };

    return status;
};
