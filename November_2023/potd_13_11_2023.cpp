#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>
#include <iostream>
#include <vector>

using namespace std;
#define int long long
long long t;

class Solution
{
public:
    // Function to find length of the shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table using bottom-up approach.
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
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