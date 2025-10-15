#include <bits/stdc++.h>        
using namespace std;

class Solution
{
public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> paths;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";

        function<void(int, int)> dfs = [&](int x, int y)
        {
            if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] || maze[x][y] == 0)
                return;
            if (x == n - 1 && y == n - 1)
            {
                paths.push_back(path);
                return;
            }

            visited[x][y] = 1;

            path.push_back('D');
            dfs(x + 1, y);
            path.pop_back();

            path.push_back('L');
            dfs(x, y - 1);
            path.pop_back();

            path.push_back('R');
            dfs(x, y + 1);
            path.pop_back();

            path.push_back('U');
            dfs(x - 1, y);
            path.pop_back();

            visited[x][y] = 0;
        };

        dfs(0, 0);
        sort(paths.begin(), paths.end());
        return paths;
    }
};
