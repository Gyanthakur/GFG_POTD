class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxIslandSize = 0;
        int islandId = 2;
        unordered_map<int, int> islandSizes;  // Maps island ID to its size
        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    int size = dfs(grid, row, col, islandId);
                    islandSizes[islandId] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    ++islandId;
                }
            }
        }
        
        // Try changing 0s to 1 and check the new island size
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    unordered_set<int> neighborIslands;
                    int newSize = 1;
                    
                    for (int dr = -1; dr <= 1; ++dr) {
                        for (int dc = -1; dc <= 1; ++dc) {
                            if (dr == 0 || dc == 0) {
                                int r = row + dr;
                                int c = col + dc;
                                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] > 1) {
                                    neighborIslands.insert(grid[r][c]);
                                }
                            }
                        }
                    }
                    
                    for (int neighbor : neighborIslands) {
                        newSize += islandSizes[neighbor];
                    }
                    
                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }
        
        return maxIslandSize;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int row, int col, int islandId) {
        int n = grid.size();
        if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] != 1) {
            return 0;
        }
        
        grid[row][col] = islandId;
        int size = 1;
        
        size += dfs(grid, row - 1, col, islandId);
        size += dfs(grid, row + 1, col, islandId);
        size += dfs(grid, row, col - 1, islandId);
        size += dfs(grid, row, col + 1, islandId);
        
        return size;
    }
};