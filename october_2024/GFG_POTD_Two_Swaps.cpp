//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    bool checkSorted(vector<int> &arr)
    {
        // code here.
        int n = arr.size();
        int cnt = 2; // Allow up to 2 swaps
        for (int i = 0; i < n && cnt > 0; i++)
        {
            // If the current element is not at its correct position
            while (arr[i] != i + 1)
            {
                swap(arr[i], arr[arr[i] - 1]); // Put arr[i] in its correct place
                cnt--;
                if (cnt == 0)
                    break; // Stop if no more swaps are allowed
            }
        }

        // Check if the array is sorted after the swaps
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
                return false;
        }

        if (cnt == 0)
            return true;
    }
};