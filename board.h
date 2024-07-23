#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <vector>

class Board {
    int length = 9;
    /*
    int defaultSudoku[9][9] = {
        {2,0,0,6,0,7,5,0,0},
        {0,0,0,0,0,0,0,9,6},
        {6,0,7,0,0,1,3,0,0},
        {0,5,0,7,3,2,0,0,0},
        {0,7,0,0,0,0,0,2,0},
        {0,0,0,1,8,9,0,7,0},
        {0,0,3,5,0,0,6,0,4},
        {8,4,0,0,0,0,0,0,0},
        {0,0,5,2,0,6,0,0,8},
    };
    */

    //array to vector
    std::vector<std::vector<int>> defaultBoard;


public:
    std::vector<std::vector<int>> currentBoard;

    Board() {

        // Zmiana rozmiaru na 9x9
        currentBoard.resize(9); // Zmiana rozmiaru g³ównego wektora na 9
        defaultBoard.resize(9);
        for (int i = 0; i < 9; ++i) {
            currentBoard[i].resize(9); // Zmiana rozmiaru ka¿dego wewnêtrznego wektora na 9
            defaultBoard[i].resize(9);
        }

        generateSudoku();

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                currentBoard[i][j] = defaultBoard[i][j];
            }
        }
    }

    void print();
    bool checkIfCompleted();
    void clearBoard();
    bool isInBounds(int val);
    bool add(int row, int col, int value);
    bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num);
    bool solveSudoku(std::vector<std::vector<int>>& board, int row = 0, int col = 0);
    void generateSudoku();
    void removeNumbers(std::vector<std::vector<int>>& board, int numToRemove);
    void newGame();
};
#endif // BOARD_H_INCLUDED
