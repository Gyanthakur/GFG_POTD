#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeReverse(string s)
    {
        unordered_map<char, int> m;
        unordered_set<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
        }
        int dir = 0;
        int i = 0;
        int e = n - 1;
        while (s.size() > st.size())
        {
            if (dir == 0)
            {
                if (m[s[i]] <= 1)
                {
                    i++;
                }
                else
                {
                    m[s[i]]--;
                    s.erase(s.begin() + i);
                    e = s.size() - 1;
                    dir = 1;
                }
            }
            else
            {
                if (m[s[e]] <= 1)
                {
                    e--;
                }
                else
                {
                    m[s[e]]--;
                    s.erase(s.begin() + e);
                    i = 0;
                    dir = 0;
                }
            }
        }
        string d = s;
        reverse(d.begin(), d.end());
        if (dir == 0)
        {
            return s;
        }
        else
        {
            return d;
        }
    }
};