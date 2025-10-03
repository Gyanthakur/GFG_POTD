#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k)
                sum--;
            else
                sum++;

            if (sum > 0)
                ans = i + 1;
            else {
                if (mp.find(sum - 1) != mp.end()) {
                    ans = max(ans, i - mp[sum - 1]);
                }
            }

            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2, 4, 5, 1, 2};
    int k = 3;

    cout << "Longest subarray length: " << sol.longestSubarray(arr, k) << endl;

    return 0;
}
