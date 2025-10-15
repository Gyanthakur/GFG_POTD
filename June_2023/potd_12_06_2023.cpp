#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        // code here
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        return dp[n];
    }
};