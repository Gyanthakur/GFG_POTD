// POTD: Sort Colors
// URL: https://practice.geeksforgeeks.org/problems/sort-colors
// # Github username: <BhuwanSKumar>

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// Test cases
int main() {
    vector<int> v1 = {2,0,2,1,1,0};
    sortColors(v1);
    for(int x : v1) cout << x << " ";
    cout << endl;

    vector<int> v2 = {};
    sortColors(v2);
    for(int x : v2) cout << x << " ";
    cout << endl;

    vector<int> v3 = {0,0,0};
    sortColors(v3);
    for(int x : v3) cout << x << " ";
    cout << endl;

    return 0;
}
