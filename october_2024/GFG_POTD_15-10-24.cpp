// Subarray range with given sum

/*
Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.
*/

/*
    Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
    Output: 3
    Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
*/

// solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        unordered_map<int,int> mp;
        int n = arr.size();
        int sum = 0;
        int cnt=  0;
        for(int i = 0 ; i < n ; i++){
            sum+=arr[i];
            if(sum == tar) cnt++;
            if(mp.find(sum - tar) != mp.end()){
                cnt+=mp[sum-tar];
            }
            mp[sum]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends
