#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

void solution()
{
}

class Solution
{
public:
    long long mod = 1e9 + 7;
    long long solverec(int i)
    {
        if (i < 0)
            return 0;
        if (i == 0)
            return 1;

        return (solverec(i - 1) + solverec(i - 2) + solverec(i - 3)) % mod;
    }

    long long solveMem(int i, vector<int> &dp)
    {
        if (i < 0)
            return 0;
        if (i == 0)
            return 1;
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = (solveMem(i - 1, dp) + solveMem(i - 2, dp) + solveMem(i - 3, dp)) % mod;
    }

    long long countWays(int n)
    {
        vector<int> dp(n + 1, -1);
        // return solverec(n);
        return solveMem(n, dp);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}