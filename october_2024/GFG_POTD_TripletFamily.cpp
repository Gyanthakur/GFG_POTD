//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    bool findTriplet(vector<int> &arr)
    {
        // Your code
        sort(arr.begin(), arr.end()); // O(n*log(n))
        // O(n^2)
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int j = 0, k = i - 1;

            while (j < k)
            {
                int sum = arr[j] + arr[k];
                if (sum == arr[i])
                    return 1;
                else if (sum > arr[i])
                    k--;
                else if (sum < arr[i])
                    j++;
            }
        }
        return 0;
    }
};