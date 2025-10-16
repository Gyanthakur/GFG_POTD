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
    // Function to count distinct subsequences using dynamic programming
    int countDistinctSubsequences(const string &str)
    {
        const int MOD = 1000000007;
        int n = str.length();

        // Array to store the last occurrence index of each character
        int lastOccurrence[256];
        memset(lastOccurrence, -1, sizeof(lastOccurrence));

        // Dynamic programming array to store count of distinct subsequences
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string has one subsequence

        // Iterate through each character of the string
        for (int i = 1; i <= n; i++)
        {
            // Calculate count based on the recurrence relation
            dp[i] = (2 * dp[i - 1]) % MOD;

            // Subtract count of subsequences ending at the last occurrence of the current character
            if (lastOccurrence[str[i - 1]] != -1)
            {
                dp[i] = (dp[i] - dp[lastOccurrence[str[i - 1]] - 1] + MOD) % MOD;
            }

            // Update last occurrence index of the current character
            lastOccurrence[str[i - 1]] = i;
        }

        // Return the final count of distinct subsequences
        return dp[n];
    }

    // Function to find the better string based on distinct subsequences count
    string betterString(const string &str1, const string &str2)
    {
        // Count distinct subsequences for each string
        int count1 = countDistinctSubsequences(str1);
        int count2 = countDistinctSubsequences(str2);

        // Compare counts and return the better string
        return (count1 >= count2) ? str1 : str2;
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