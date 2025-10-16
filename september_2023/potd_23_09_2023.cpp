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
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        long long prev_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (prev_sum == sum - a[i])
            {
                return i + 1;
            }
            prev_sum += a[i];
            sum -= a[i];
        }
        return -1;
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