#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, current, 0, k, n, result);
        return result;
    }

private:
    void backtrack(int start, vector<int> &current, int sum, int k, int n, vector<vector<int>> &result)
    {
        if (current.size() == k)
        {
            if (sum == n)
                result.push_back(current);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            if (sum + i > n)
                break;
            current.push_back(i);
            backtrack(i + 1, current, sum + i, k, n, result);
            current.pop_back();
        }
    }
};
