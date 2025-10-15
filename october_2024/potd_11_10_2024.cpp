#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrange(const vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        vector<int> ans(n, -1);
        for (int x : arr)
        {
            if (x < n && x >= 0)
                ans[x] = x;
        }
        return ans;
    }
};