#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> temp;
        temp.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            auto ind = lower_bound(temp.begin(), temp.end(), a[i]);
            if (ind != temp.end())
                temp[ind - temp.begin()] = a[i];
            else
                temp.push_back(a[i]);
        }

        return temp.size();
    }
};