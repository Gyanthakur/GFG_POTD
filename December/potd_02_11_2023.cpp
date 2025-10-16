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
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return 0;
            }
        }
        return 1;
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