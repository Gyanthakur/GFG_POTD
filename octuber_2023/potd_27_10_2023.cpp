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
    int minimumNumberOfDeletions(string S)
    {
        // code here
        int n = S.length();

        // Create a 2D table to store the length of the LPS
        vector<vector<int>> table(n, vector<int>(n, 0));

        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++)
        {
            table[i][i] = 1;
        }

        // Fill the table in a bottom-up manner
        for (int cl = 2; cl <= n; cl++)
        {
            for (int i = 0; i < n - cl + 1; i++)
            {
                int j = i + cl - 1;
                if (S[i] == S[j] && cl == 2)
                {
                    table[i][j] = 2;
                }
                else if (S[i] == S[j])
                {
                    table[i][j] = table[i + 1][j - 1] + 2;
                }
                else
                {
                    table[i][j] = max(table[i][j - 1], table[i + 1][j]);
                }
            }
        }

        // The length of the LPS
        int lps_length = table[0][n - 1];

        // Minimum number of deletions to make a palindrome
        int min_deletions = n - lps_length;

        return min_deletions;
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