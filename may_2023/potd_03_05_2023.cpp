#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    bool makePalindrome(int n, vector<string> &arr)
    {
        map<string, int> mp;
        for (auto it : arr)
            mp[it]++;

        for (auto str : arr)
        {
            string rev = str;
            reverse(rev.begin(), rev.end());
            if (mp.find(rev) == mp.end())
            {
                return false;
            }
            else
            {
                if (mp[rev] > 1)
                    mp[rev]--;
                else
                    mp.erase(rev);
            }
        }
        return true;
    }
};