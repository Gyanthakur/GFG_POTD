#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution {
public:
    int dx[4] = { -1 ,0 ,0, 1};
    int dy[4] = { 0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& n, int& m) {
        grid[i][j] = -1;
        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                dfs(grid, x, y, n, m);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }

        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cnt += (grid[i][j] == 1);
        }
        return cnt;
    }
};
void solution()
{

}
signed main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}