#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>
using namespace std;
#define int long long
long long t;
int solve(int arr[], int n, int index, vector<int> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int pick = arr[index] + solve(arr, n, index + 2, dp);
    int notpick = solve(arr, n, index + 1, dp);
    return dp[index] = max(pick, notpick);
}
int FindMaxSum(int arr[], int n)
{
    // Your code here
    vector<int> dp(n, -1);
    return solve(arr, n, 0, dp);
}
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