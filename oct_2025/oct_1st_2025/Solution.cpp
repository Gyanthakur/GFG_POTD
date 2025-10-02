#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& path) {
        if (nums.empty()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 

            int val = nums[i];
            nums.erase(nums.begin() + i);
            path.push_back(val);

            backtrack(nums, result, path);

            path.pop_back(); 
            nums.insert(nums.begin() + i, val);
        }
    }

    static vector<vector<int>> uniquePerms(vector<int> nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(nums, result, path);
        return result;
    }
};
