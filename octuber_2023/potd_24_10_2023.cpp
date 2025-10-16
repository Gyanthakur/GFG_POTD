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
private:
    bool IsPalindrome(string &str, int i, int j)
    {
        if (i >= j)
            return true;

        if (str[i] != str[j])
            return false;
        return (IsPalindrome(str, i + 1, j - 1));
    }

public:
    int palindromicPartition(string str)
    {
        int st = 0;
        int n = str.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {

            int ans = (int)1e9;

            for (int k = i; k < n; k++)
            {
                if (IsPalindrome(str, i, k) == true)
                {

                    // i...k -> first part and k+1...size -> second part
                    int cur = 1 + dp[k + 1];

                    ans = min(ans, cur);
                }
            }
            dp[i] = ans;
        }
        return dp[0] - 1;
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