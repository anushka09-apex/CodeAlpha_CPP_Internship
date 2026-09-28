#include <iostream>
using namespace std;

const int SIZE = 9;

// Display the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    cout << "\n+-------+-------+-------+\n";

    for (int row = 0; row < SIZE; row++) {
        cout << "| ";

        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";

            if ((col + 1) % 3 == 0)
                cout << "| ";
        }

        cout << "\n";

        if ((row + 1) % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

// Check whether a number already exists in a row
bool isUsedInRow(int board[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] == num)
            return true;
    }

    return false;
}

// Check whether a number already exists in a column
bool isUsedInColumn(int board[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col] == num)
            return true;
    }

    return false;
}

// Check whether a number already exists in a 3x3 box
bool isUsedInBox(int board[SIZE][SIZE], int startRow,
                 int startCol, int num) {

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            if (board[startRow + row][startCol + col] == num)
                return true;
        }
    }

    return false;
}

// Check whether a number can safely be placed
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {

    if (isUsedInRow(board, row, num))
        return false;

    if (isUsedInColumn(board, col, num))
        return false;

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    if (isUsedInBox(board, boxRow, boxCol, num))
        return false;

    return true;
}

// Validate the initial Sudoku puzzle
bool validateBoard(int board[SIZE][SIZE]) {

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {

            int num = board[row][col];

            if (num == 0)
                continue;

            // Temporarily remove the number
            board[row][col] = 0;

            if (!isSafe(board, row, col, num)) {
                board[row][col] = num;
                return false;
            }

            board[row][col] = num;
        }
    }

    return true;
}

// Find an empty cell
bool findEmptyCell(int board[SIZE][SIZE], int &row, int &col) {

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {

            if (board[row][col] == 0)
                return true;
        }
    }

    return false;
}

// Solve Sudoku using backtracking
bool solveSudoku(int board[SIZE][SIZE]) {

    int row, col;

    // No empty cells means the puzzle is solved
    if (!findEmptyCell(board, row, col))
        return true;

    // Try numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(board, row, col, num)) {

            // Place number
            board[row][col] = num;

            // Recursively solve the remaining puzzle
            if (solveSudoku(board))
                return true;

            // Backtrack if this choice does not work
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int board[SIZE][SIZE];

    cout << "====================================\n";
    cout << "       CODEALPHA SUDOKU SOLVER\n";
    cout << "====================================\n";

    cout << "\nEnter the Sudoku puzzle.\n";
    cout << "Use 0 for empty cells.\n";
    cout << "Enter 9 numbers for each row.\n\n";

    // Take Sudoku input from the user
    for (int row = 0; row < SIZE; row++) {

        cout << "Enter row " << row + 1 << ": ";

        for (int col = 0; col < SIZE; col++) {
            cin >> board[row][col];

            // Validate input range
            if (board[row][col] < 0 ||
                board[row][col] > 9) {

                cout << "\nInvalid input. "
                     << "Only numbers 0 to 9 are allowed.\n";

                return 0;
            }
        }
    }

    cout << "\nOriginal Sudoku:";
    printBoard(board);

    // Validate the initial puzzle
    if (!validateBoard(board)) {

        cout << "\nInvalid Sudoku puzzle!\n";
        cout << "There is a duplicate number in a row, "
             << "column, or 3x3 box.\n";

        return 0;
    }

    // Solve the puzzle
    if (solveSudoku(board)) {

        cout << "\nSolved Sudoku:";
        printBoard(board);

    } else {

        cout << "\nNo solution exists for this Sudoku puzzle.\n";
    }

    return 0;
}