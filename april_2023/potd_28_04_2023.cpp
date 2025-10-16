#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
    {
        // Code here

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> ans(n, vector<int>(m, 0));

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (c[i][j] == 'W')
                {
                    q.push({i, {j, 0}});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second.first;
            int dis = q.front().second.second;

            if (c[x][y] == 'H')
            {
                ans[x][y] = 2 * dis;
            }

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && (c[nx][ny] == 'H' || c[nx][ny] == '.'))
                {
                    vis[nx][ny] = 1;
                    q.push({nx, {ny, dis + 1}});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && c[i][j] == 'H')
                    ans[i][j] = -1;
            }
        }

        return ans;
    }
};