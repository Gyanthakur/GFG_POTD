#include <bits/stdc++.h>    
using namespace std;

class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr)
    {
        vector<int> ans;
        unordered_set<int> st;
        for (int &it : arr)
        {
            if (st.find(it) == st.end())
            {
                ans.push_back(it);
                st.insert(it);
            }
        }
        return ans;
    }
};