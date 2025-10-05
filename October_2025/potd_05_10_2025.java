class Solution {
    public ArrayList<String> ratInMaze(int[][] maze) {
        ArrayList<String> result = new ArrayList<>();
        int n = maze.length;

        if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return result;

        boolean[][] visited = new boolean[n][n];
        solve(0, 0, maze, n, "", visited, result);

        Collections.sort(result); // Lexicographical order
        return result;
    }

    private void solve(int row, int col, int[][] maze, int n, String path, boolean[][] visited, ArrayList<String> result) {
       
        if (row == n - 1 && col == n - 1) {
            result.add(path);
            return;
        }


        visited[row][col] = true;

        // Move Down
        if (isSafe(row + 1, col, maze, visited, n))
            solve(row + 1, col, maze, n, path + "D", visited, result);

        // Move Left
        if (isSafe(row, col - 1, maze, visited, n))
            solve(row, col - 1, maze, n, path + "L", visited, result);

        // Move Right
        if (isSafe(row, col + 1, maze, visited, n))
            solve(row, col + 1, maze, n, path + "R", visited, result);

        // Move Up
        if (isSafe(row - 1, col, maze, visited, n))
            solve(row - 1, col, maze, n, path + "U", visited, result);

        // Backtrack
        visited[row][col] = false;
    }

    private boolean isSafe(int row, int col, int[][] maze, boolean[][] visited, int n) {
        return row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1 && !visited[row][col];
    }
}
