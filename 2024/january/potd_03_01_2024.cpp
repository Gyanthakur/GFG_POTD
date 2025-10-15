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
    int smallestSubstring(string S)
    {
        int zero = -1, one = -1, two = -1;
        int ans = 1e9;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '0')
                zero = i;
            if (S[i] == '1')
                one = i;
            if (S[i] == '2')
                two = i;

            if (zero != -1 and one != -1 and two != -1)
            {
                ans = min(ans, max(zero, max(one, two)) - min(zero, min(one, two)) + 1);
            }
        }

        if (ans == 1e9)
            return -1;
        return ans;
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