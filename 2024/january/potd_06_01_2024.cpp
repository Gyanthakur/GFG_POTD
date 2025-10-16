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
    int primeFactor(int n)
    {
        int cnt = 0;
        while (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
        }
        if (n > 2)
        {
            cnt++;
        }
        return cnt;
    }

public:
    int sumOfPowers(int a, int b)
    {
        // Code here
        int ans = 0;
        for (int i = a; i <= b; i++)
        {
            ans += primeFactor(i);
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