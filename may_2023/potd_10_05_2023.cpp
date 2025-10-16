#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int totalCuts(int N, int K, vector<int> &A)
    {
        // Code here
        vector<int> pref(N, 0);
        pref[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            pref[i] = min(pref[i + 1], A[i]);
        }
        int maxi = A[0];
        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            if (maxi + pref[i] >= K)
                ans++;
            maxi = max(maxi, A[i]);
        }
        return ans;
    }
};