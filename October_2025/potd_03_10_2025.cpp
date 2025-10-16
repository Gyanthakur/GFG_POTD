#include <bits/stdc++.h>
using namespace std;    

class Solution
{
public:
    void helper(int i, string &temp, vector<string> &ans, vector<int> &arr, unordered_map<int, vector<char>> &mpp)
    {
        if (i >= arr.size())
        {
            ans.push_back(temp);
            return;
        }
        if (mpp.find(arr[i]) == mpp.end())
        {
            helper(i + 1, temp, ans, arr, mpp);
            return;
        }
        for (int j = 0; j < mpp[arr[i]].size(); j++)
        {
            temp += mpp[arr[i]][j];
            helper(i + 1, temp, ans, arr, mpp);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr)
    {
        // code here
        unordered_map<int, vector<char>> mpp;
        mpp[2] = {'a', 'b', 'c'};
        mpp[3] = {'d', 'e', 'f'};
        mpp[4] = {'g', 'h', 'i'};
        mpp[5] = {'j', 'k', 'l'};
        mpp[6] = {'m', 'n', 'o'};
        mpp[7] = {'p', 'q', 'r', 's'};
        mpp[8] = {'t', 'u', 'v'};
        mpp[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        string temp = "";
        helper(0, temp, ans, arr, mpp);
        return ans;
    }
};