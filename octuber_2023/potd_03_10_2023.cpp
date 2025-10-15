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
    string colName(long long int n)
    {
        // your code here
        if (n == 0)
            return "";
        return colName((n - 1) / 26) + char(65 + (n - 1) % 26);
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