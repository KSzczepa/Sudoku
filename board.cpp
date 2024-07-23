#include "board.h"
#include <cassert>
#include <iostream>
#include <Windows.h> // for displaying colors
#include <ctime>
#include <cstdlib>

void Board::print() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int row=0; row<9; row++) {
        for (int col=0; col<9; col++) {
            if (defaultBoard[row][col] != 0) {
                SetConsoleTextAttribute(hConsole, 10);
            }
            if (currentBoard[row][col] == 0) {
                std::cout << " _ ";
            }
            else {
                std::cout << " " << currentBoard[row][col] << " ";
            }
            SetConsoleTextAttribute(hConsole, 7);
            if (col == 2 || col == 5)
                std::cout << "|";
        }
        std::cout << std::endl;
        if (row == 2 || row == 5)
            std::cout << "-----------------------------" << std::endl;
    }

};


bool Board::checkIfCompleted() {
    for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                if (currentBoard[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
};

void Board::clearBoard() {
    for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                currentBoard[i][j] = defaultBoard[i][j];
            }
        }
};

bool Board::isInBounds(int val) {
    if (val < 1 || val > 9)
        return false;
    else
        return true;
};

bool Board::add(int row, int col, int value) {

    if (!isInBounds(row) || !isInBounds(col)) {
        std::cout << "Type correct row/col number!" << std::endl;
        return false;
    }
    else if (!isInBounds(value)) {
        std::cout << "Value is incorrect!" << std::endl;
        return false;
    }
    else {
        if (defaultBoard[row-1][col-1] != 0) {
            std::cout << "You cannot change this value!" << std::endl;
            return false;
        }
        else {
            currentBoard[row-1][col-1] = value;
            return true;
        }
    }
};

// Funkcja sprawdzaj¹ca, czy liczba mo¿e byæ umieszczona na planszy
bool Board::isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    // Check if we find the same num
    // in the similar row , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (board[row][x] == num)
            return false;

    // Check if we find the same num in
    // the similar column , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (board[x][col] == num)
            return false;

    // Check if we find the same num in
    // the particular 3*3 matrix,
    // we return false
    int startRow = row - row % 3,
            startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j +
                            startCol] == num)
                return false;

    return true;
};

// Solving Sudoku function (backtracking algorithm)
bool Board::solveSudoku(int row, int col) {
    int N = 9;

    // Check if we have reached the 8th
    // row and 9th column (0
    // indexed matrix) , we are
    // returning true to avoid
    // further backtracking
    if (row == N - 1 && col == N)
        return true;

    // Check if column value  becomes 9 ,
    // we move to next row and
    //  column start from 0
    if (col == N) {
        row++;
        col = 0;
    }

    // Check if the current position of
    // the currentBoard already contains
    // value >0, we iterate for next column
    if (currentBoard[row][col] > 0)
        return solveSudoku(row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        // Check if it is safe to place
        // the num (1-9)  in the
        // given row ,col  ->we
        // move to next column
        if (isSafe(currentBoard, row, col, num))
        {

           /* Assigning the num in
              the current (row,col)
              position of the currentBoard
              and assuming our assigned
              num in the position
              is correct     */
            currentBoard[row][col] = num;

            //  Checking for next possibility with next
            //  column
            if (solveSudoku(row, col + 1))
                return true;
        }

        // Removing the assigned num ,
        // since our assumption
        // was wrong , and we go for
        // next assumption with
        // diff num value
        currentBoard[row][col] = 0;
    }
    return false;

};

void Board::generateSudoku() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            defaultBoard[i][j] = 0;
        }
    }
    for (int i = 0; i < 9; ++i) {
        int num = std::rand() % 9 + 1;
        while (!isSafe(defaultBoard, i, i, num)) {
            num = std::rand() % 9 + 1;
        }
        defaultBoard[i][i] = num;
    }
//    solveSudoku(defaultBoard);
};
