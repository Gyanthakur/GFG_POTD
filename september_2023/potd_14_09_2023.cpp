#include <bits/stdc++.h>
using namespace std;
#define int long long
long long t, a[100005];
int mod = 1e9 + 7;

int f(int i, int n, int arr[], int sum, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }

    // if(sum == 0)
    //     return 1;

    if (dp[i][sum] != -1)
        return dp[i][sum];
    int pick = 0, notPick;

    if (arr[i] <= sum)
    {
        pick = f(i + 1, n, arr, sum - arr[i], dp);
    }

    notPick = f(i + 1, n, arr, sum, dp);

    return dp[i][sum] = (pick % mod + notPick % mod) % mod;
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(0, n, arr, sum, dp);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}