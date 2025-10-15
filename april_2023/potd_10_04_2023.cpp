#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIntersections(vector<vector<int>> lines, int N)
    {
        map<int, int> mp;
        for (auto it : lines)
        {
            int start = it[0];
            int end = it[1] + 1;
            mp[start]++;
            mp[end]--;
        }

        int prefix = 0;
        int ans = 1;
        for (auto it : mp)
        {
            prefix = prefix + it.second;
            ans = max(ans, prefix);
        }
        return ans;
    }
};