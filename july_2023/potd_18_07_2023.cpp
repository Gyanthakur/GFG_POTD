#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{

public:
    int LongestRepeatingSubsequence(std::string str)
    {

        int n = str.length();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i)
        {

            for (int j = 1; j <= n; ++j)
            {

                if (str[i - 1] == str[j - 1] && i != j)
                {

                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {

                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};