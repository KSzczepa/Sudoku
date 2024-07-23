#include "game.h"
#include "board.h"
#include <iostream>
#include <cstdlib>

gameResult_e game(Board &board) {
    gameResult_e res = OK;
    static gameStatus_e status = NEW;
    int nr = 0;
    level_e lvl = UNKNOWN;

    clearConsole();
    printWelcomeMsg();

    if (status == NEW) {
        lvl = handleDifficultyLvl();
        board.setGameLevel(lvl);
        clearConsole();
        printWelcomeMsg();
    }

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

level_e handleDifficultyLvl() {
    int input = 0;

    std::cout << "Choose difficulty level" << std:: endl;
    std::cout << " 1 - EASY" << std::endl;
    std::cout << " 2 - MEDIUM" << std::endl;
    std::cout << " 3 - HARD" << std::endl;

    do {
        std::cin >> input;

        if (input < 1 || input > 3) {
            std::cout << " Choose again" << std::endl;
        }
    } while (input < 1 || input > 3);

    return static_cast<level_e>(input);
};

void printMenu(gameStatus_e status) {
    if (status == NEW) {
        std::cout << " 1 - enter number" << std::endl;
        std::cout << " 2 - show result" << std::endl;
        std::cout << " 0 - end game" << std::endl;
    }
    else if (status == IN_PROGRESS) {
        std::cout << " 1 - enter number" << std::endl;
        std::cout << " 2 - show result" << std::endl;
        std::cout << " 3 - start again" << std::endl;
        std::cout << " 4 - new game" << std::endl;
        std::cout << " 0 - end game" << std::endl;
    }
    else {
        std::cout << " 3 - start again" << std::endl;
        std::cout << " 4 - new game" << std::endl;
        std::cout << " 0 - end game" << std::endl;
    }

};

gameStatus_e menuAPI(int nr, Board &b) {
    gameStatus_e status = ERROR;
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
            b.solveSudoku(b.currentBoard);
            status = SOLVED;
        }; break;
        case 3: {
            b.clearBoard();
            status = NEW;
        }; break;
        case 4: {
            b.newGame();
            status = NEW;
        }; break;
        default: {
            std::cout << "Enter another number!" << std::endl;
        }; break;
    };

    return status;
};
