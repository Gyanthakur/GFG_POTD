#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
long long t;

class Solution
{
public:
    int transitionPoint(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            if (arr[i] == 1)
                return i;
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