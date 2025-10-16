#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Arrays for the 8 possible Knight moves (dx, dy)
    int move_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    vector<vector<int>> knightTour(int n)
    {
        // Initialize the board with -1 (unvisited)
        vector<vector<int>> board(n, vector<int>(n, -1));

        // Start from (0, 0)
        board[0][0] = 0;

        // Start the recursive backtracking from (0, 0) with move count = 1
        if (solveTourUtil(n, board, 0, 0, 1))
        {
            return board;
        }

        // If no solution, return {{-1}}
        return {{-1}};
    }

private:
    // Check if (x, y) is within the board and unvisited
    bool isSafe(int n, vector<vector<int>> &board, int x, int y)
    {
        return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
    }

    // Count valid onward moves from (x, y) → Warnsdorff's Rule helper
    int getDegree(int n, vector<vector<int>> &board, int x, int y)
    {
        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + move_x[i];
            int ny = y + move_y[i];
            if (isSafe(n, board, nx, ny))
                count++;
        }
        return count;
    }

    // Recursive backtracking function using Warnsdorff's heuristic
    bool solveTourUtil(int n, vector<vector<int>> &board, int curr_x, int curr_y, int move_count)
    {
        // Base case: if all squares are visited
        if (move_count == n * n)
            return true;

        // Collect all valid next moves along with their degree
        vector<array<int, 3>> validMoves;
        for (int i = 0; i < 8; i++)
        {
            int nx = curr_x + move_x[i];
            int ny = curr_y + move_y[i];
            if (isSafe(n, board, nx, ny))
            {
                int degree = getDegree(n, board, nx, ny);
                validMoves.push_back({nx, ny, degree});
            }
        }

        // Sort moves by ascending degree (Warnsdorff's Rule)
        sort(validMoves.begin(), validMoves.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        // Try moves in the sorted order
        for (auto &move : validMoves)
        {
            int nx = move[0];
            int ny = move[1];

            board[nx][ny] = move_count;

            if (solveTourUtil(n, board, nx, ny, move_count + 1))
                return true;

            // Backtrack
            board[nx][ny] = -1;
        }

        return false; // No solution from this path
    }
};
