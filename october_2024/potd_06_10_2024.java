class Solution {
    
    static boolean isSafe(char[][] M, int r, int c, 
                                      boolean[][] visited) {
        int ROW = M.length;
        int COL = M[0].length;

        // r is in range, c is in range, value is '1' and not 
        // yet visited
        return r >= 0 && r < ROW && c >= 0 && c < COL 
                          && M[r][c] == '1' && !visited[r][c];
    }

    // A utility function to do DFS for a 2D matrix.
    // It only considers the 8 neighbours as adjacent vertices
    static void DFS(char[][] M, int r, int c,
                                        boolean[][] visited) {
        // These arrays are used to get r and c numbers of 8
        // neighbours of a given cell
        int[] rNbr = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] cNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };

        // Mark this cell as visited
        visited[r][c] = true;

        // Recur for all connected neighbours
        for (int k = 0; k < 8; ++k) {
            int newR = r + rNbr[k];
            int newC = c + cNbr[k];
            if (isSafe(M, newR, newC, visited)) {
                DFS(M, newR, newC, visited);
            }
        }
    }
    
    // Function to find the number of islands.
    public int numIslands(char[][] grid) {
        // Code here
         int ROW = grid.length;
        int COL = grid[0].length;

        // Make a boolean array to mark visited cells.
        // Initially all cells are unvisited
        boolean[][] visited = new boolean[ROW][COL];

        // Initialize count as 0 and traverse through all 
          // cells of the given matrix
        int count = 0;
        for (int r = 0; r < ROW; ++r) {
            for (int c = 0; c < COL; ++c) {
              
                // If a cell with value '1' is not visited yet, 
                  // then a new island is found
                if (grid[r][c] == '1' && !visited[r][c]) {
                    
                      // Visit all cells in this island.
                    DFS(grid, r, c, visited);
                    
                      // increment the island count
                    ++count;
                }
            }
        }
        return count;
    }
}
