// GFG POTD: Book Allocation Problem
// Date: 23 August 2025
// Author: Angel Agarwal

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAllocate(vector<int> &arr, int mid, int k) {
        int pages = 0;
        int book = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (pages + arr[i] <= mid) {
                pages += arr[i];
            } else {
                book++;
                pages = arr[i];
            }
        }
        return book > k;
    }
    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = 0;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (!canAllocate(arr, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
