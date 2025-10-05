import java.util.ArrayList;

class Solution {
    public ArrayList<String> ratInMaze(int[][] maze) {
        ArrayList<String> result = new ArrayList<>();
        int n = maze.length;

        // Edge case: No maze, start/end is blocked.
        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return result;
        }

        boolean[][] visited = new boolean[n][n];
        solve(0, 0, maze, n, new StringBuilder(), visited, result);

        // The final sort is no longer needed because we explore in lexicographical order.
        return result;
    }

    private void solve(int row, int col, int[][] maze, int n, StringBuilder path, boolean[][] visited, ArrayList<String> result) {
        
        // Base case: If we've reached the destination, add the path to our results.
        if (row == n - 1 && col == n - 1) {
            result.add(path.toString());
            return;
        }

        // Mark the current cell as visited for the current path
        visited[row][col] = true;

        // --- Optimized Directional Traversal ---
        // We explore in lexicographical order: Down, Left, Right, Up.
        String directions = "DLRU";
        int[] dr = { 1, 0, 0, -1 }; // Change in row for D, L, R, U
        int[] dc = { 0, -1, 1, 0 }; // Change in col for D, L, R, U

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            if (isSafe(nextRow, nextCol, maze, visited, n)) {
                // Append direction and recurse
                path.append(directions.charAt(i));
                solve(nextRow, nextCol, maze, n, path, visited, result);
                
                // Backtrack: remove the last added character to explore other paths.
                path.deleteCharAt(path.length() - 1);
            }
        }

        // Un-mark the cell when backtracking to open it up for other paths.
        visited[row][col] = false;
    }

    private boolean isSafe(int row, int col, int[][] maze, boolean[][] visited, int n) {
        // Check if the next cell is within bounds, is a valid path (1), and hasn't been visited.
        return row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1 && !visited[row][col];
    }
}