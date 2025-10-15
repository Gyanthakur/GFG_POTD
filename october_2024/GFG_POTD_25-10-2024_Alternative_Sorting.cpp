#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> alternateSort(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> ans;
        int i = 0, j = n - 1;
        while (i < j)
        {
            ans.push_back(arr[j--]);
            ans.push_back(arr[i++]);
        }
        if (n % 2 != 0)
            ans.push_back(arr[i]);
        return ans;
    }
};