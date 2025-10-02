#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(1, k, n, path, result);
        return result;
    }

    void backtrack(int start, int k, int target, vector<int>& path, vector<vector<int>>& result) {
        if (k == 0 && target == 0) {
            result.push_back(path);
            return;
        }
        if (k == 0 || target < 0) return;

        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(i + 1, k - 1, target - i, path, result);
            path.pop_back();
        }
    }
};
