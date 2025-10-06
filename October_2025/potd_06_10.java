import java.util.ArrayList;
import java.util.Comparator;

class Solution {
    // Arrays for the 8 possible Knight moves (dx, dy)
    private final int[] move_x = {2, 1, -1, -2, -2, -1, 1, 2};
    private final int[] move_y = {1, 2, 2, 1, -1, -2, -2, -1};

    public ArrayList<ArrayList<Integer>> knightTour(int n) {
        // Initialize the board with -1s to represent unvisited squares.
        ArrayList<ArrayList<Integer>> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(-1); // -1 for unvisited
            }
            board.add(row);
        }

        // Start at (0, 0) as the 0th move (Step 0)
        board.get(0).set(0, 0);

        // Start the recursive backtracking from (0, 0) with move count 1
        // The total number of steps to visit is n*n. Since we start at 0, 
        // the last step will be n*n - 1. We look for a move_count of n*n.
        if (solveTourUtil(n, board, 0, 0, 1)) {
            // Solution found.
            return board;
        } else {
            // No solution found. Return the mandated error format.
            ArrayList<ArrayList<Integer>> noSolution = new ArrayList<>();
            ArrayList<Integer> row = new ArrayList<>();
            row.add(-1);
            noSolution.add(row);
            return noSolution;
        }
    }

    // Checks if (x, y) is on board and unvisited (-1)
    private boolean isSafe(int n, ArrayList<ArrayList<Integer>> board, int x, int y) {
        return (x >= 0 && x < n && 
                y >= 0 && y < n && 
                board.get(x).get(y) == -1);
    }
    
    // Warnsdorff's Rule Helper: Counts valid onward moves from (x, y)
    private int getDegree(int n, ArrayList<ArrayList<Integer>> board, int x, int y) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];
            if (isSafe(n, board, next_x, next_y)) {
                count++;
            }
        }
        return count;
    }

    // Optimized Backtracking recursive function using Warnsdorff's Rule
    private boolean solveTourUtil(int n, ArrayList<ArrayList<Integer>> board, int curr_x, int curr_y, int move_count) {
        
        // Base Case: Tour complete (n*n squares visited). 
        // Since we started at 0, the last step is n*n - 1. move_count will reach n*n.
        if (move_count == n * n) {
            return true;
        }

        // 1. Collect all valid next moves and their 'degree' (Warnsdorff's requirement)
        ArrayList<int[]> validMoves = new ArrayList<>();
        for (int i = 0; i < 8; i++) {
            int next_x = curr_x + move_x[i];
            int next_y = curr_y + move_y[i];
            
            if (isSafe(n, board, next_x, next_y)) {
                // Calculate degree *before* making the move
                int degree = getDegree(n, board, next_x, next_y);
                // Store {next_x, next_y, degree}
                validMoves.add(new int[]{next_x, next_y, degree}); 
            }
        }
        
        // 2. Sort moves by ascending degree (Warnsdorff's Rule: minimum onward moves first)
        // This is the optimization that prevents TLE.
        validMoves.sort(Comparator.comparingInt(a -> a[2]));

        // 3. Try moves in the sorted order
        for (int[] move : validMoves) {
            int next_x = move[0];
            int next_y = move[1];

            // Action: Mark the square with the current move_count
            board.get(next_x).set(next_y, move_count);

            // Recurse: Go to the next move count
            if (solveTourUtil(n, board, next_x, next_y, move_count + 1)) {
                return true; // Solution found
            }

            // Backtrack: Reset the square to unvisited
            board.get(next_x).set(next_y, -1);
        }

        // Failure: If all sorted moves led to a dead end
        return false;
    }
}