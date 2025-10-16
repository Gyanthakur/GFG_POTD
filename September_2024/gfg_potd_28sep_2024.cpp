/*
GFG POTD 28 sep 2024

Problem Description:-

There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following:
Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred,
where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum


*/

// Solution in C++

#include <bits/stdc++.h>

using namespace std;

int minimizeCost(int n, int k, vector<int> &arr)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
        }
    }

    return dp.back();
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minimizeCost(n, k, arr) << endl;
    return 0;
}