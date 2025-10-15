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
    int numberSequence(int m, int n)
    {
        // code here
        if (n == 0)
            return 0;
        if (n == 1)
            return m;
        int sum = 0;
        for (int i = 1; i <= m; i++)
        {
            sum += numberSequence(i / 2, n - 1);
        }
        return sum;
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