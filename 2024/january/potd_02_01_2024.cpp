#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>
using namespace std;
// #define int long long
long long t;

class Solution
{
public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k)
    {
        long long int sum = 0, sum2 = 0, ans = LLONG_MIN;
        int cnt = 0;

        for (int i = 0, j = 0; i < n; ++i)
        {
            sum += a[i];
            if (i - j + 1 >= k)
            {
                sum -= a[j];
                if (sum2 < 0)
                    sum2 = 0;
                sum2 += a[j++];
                ans = max(ans, sum + sum2);
            }
        }

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