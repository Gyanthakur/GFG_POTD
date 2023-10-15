#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in a cell
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if 'num' is not present in the current row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not present in the current 3x3 subgrid
    int subgridSize = 3;
    int startRow = row - (row % subgridSize);
    int startCol = col - (col % subgridSize);
    for (int i = 0; i < subgridSize; i++) {
        for (int j = 0; j < subgridSize; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row = -1, col = -1;
    bool isEmpty = true;

    // Find the first empty cell
    for (int i = 0; i < N && isEmpty; i++) {
        for (int j = 0; j < N && isEmpty; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
            }
        }
    }

    // If there are no empty cells, the Sudoku is solved
    if (isEmpty) {
        return true;
    }

    // Try filling the empty cell with numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0; // If the current placement doesn't lead to a solution, reset the cell
        }
    }

    return false; // No solution found
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N, 0));

    cout << "Enter the Sudoku grid (row by row, use 0 for empty cells):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
