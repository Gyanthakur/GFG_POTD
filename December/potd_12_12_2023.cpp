#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

class Solution
{
public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &M, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int a = solve(i - 1, j + 1, n, m, M, dp);
        int b = solve(i, j + 1, n, m, M, dp);
        int c = solve(i + 1, j + 1, n, m, M, dp);

        return dp[i][j] = max(max(a, b), c) + M[i][j];
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++)
        {
            int a = solve(i, 0, n, m, M, dp);
            if (a > ans)
                ans = a;
        }

        return ans;
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
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}