# CodeAlpha Sudoku Solver

## Description

This is a C++ console-based Sudoku Solver developed as part of the CodeAlpha C++ Internship.

The program accepts a 9x9 Sudoku puzzle from the user and solves it using a backtracking algorithm.

## Features

- Accepts a 9x9 Sudoku puzzle
- Uses 0 for empty cells
- Validates the initial puzzle
- Checks rows
- Checks columns
- Checks 3x3 boxes
- Uses recursive backtracking
- Displays the solved Sudoku
- Reports when no solution exists

## Algorithm

The program uses the Backtracking algorithm.

The solver:

1. Finds an empty cell.
2. Tries numbers from 1 to 9.
3. Checks whether the number is valid.
4. Places the number if it is safe.
5. Recursively solves the remaining cells.
6. Backtracks when a selected number leads to an invalid solution.

## Technologies Used

- C++
- Standard C++ Library

## How to Run

1. Compile the program using a C++ compiler.
2. Run the program.
3. Enter 9 rows containing 9 numbers each.
4. Use `0` for empty cells.
5. The program validates and solves the Sudoku puzzle.

## Example Input

```text
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9