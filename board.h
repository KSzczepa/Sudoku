#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <vector>
#include "types.h"


class Board {
    int length = 9;

    std::vector<std::vector<int>> defaultBoard;
    int numToRemove = 40;


public:
    std::vector<std::vector<int>> currentBoard;
    level_e level = EASY;

    Board() {

        // Set size to 9x9
        currentBoard.resize(length);
        defaultBoard.resize(length);
        for (int i = 0; i < length; ++i) {
            currentBoard[i].resize(length);
            defaultBoard[i].resize(length);
        }

        generateSudoku();

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                currentBoard[i][j] = defaultBoard[i][j];
            }
        }
    }

    void print();
    bool checkIfCompleted();
    void clearBoard();
    bool add(int row, int col, int value);
    bool solveSudoku(std::vector<std::vector<int>>& board, int row = 0, int col = 0);
    void newGame();
    void setGameLevel(level_e lvl);

protected:
    void setNumToRemove(int num);
    int getNumToRemove();
    void generateSudoku();
    bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num);
    bool isInBounds(int val);
    int getRandomNumber(int min, int max);
    void removeNumbers(std::vector<std::vector<int>>& board, int numToRemove);
};
#endif // BOARD_H_INCLUDED
