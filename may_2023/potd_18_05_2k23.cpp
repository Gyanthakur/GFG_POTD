#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    vector<vector<bool>> vis;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int x, int y, int n, int m, vector<vector<int>> &matrix)
    {
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 1 && !vis[nx][ny])
                dfs(nx, ny, n, m, matrix);
        }
    }
    
    int closedIslands(vector<vector<int>> &matrix, int n, int m)
    {
        vis.resize(n, vector<bool>(m, 0));
        // first row and last row
        for (int j = 0; j < m; ++j)
        {
            if (!vis[0][j] && matrix[0][j] == 1)
            {
                dfs(0, j, n, m, matrix);
            }
            if (matrix[n - 1][j] == 1 && !vis[n - 1][j])
            {
                dfs(n - 1, j, n, m, matrix);
            }
        }
        // first and last col
        for (int j = 0; j < n; ++j)
        {
            if (!vis[j][0] && matrix[j][0] == 1)
            {
                dfs(j, 0, n, m, matrix);
            }
            if (matrix[j][m - 1] == 1 && !vis[j][m - 1])
            {
                dfs(j, m - 1, n, m, matrix);
            }
        }

        int count = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < m - 1; ++j)
            {
                if (matrix[i][j] == 1 && !vis[i][j])
                {
                    count++;
                    dfs(i, j, n, m, matrix);
                }
            }
        }
        return count;
    }
};