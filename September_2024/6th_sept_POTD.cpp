/* Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 992K+Points: 4

Given an integer array arr[]. You need to find and return the maximum sum possible from all the subarrays.

Examples:

Input: arr[] = [1, 2, 3, -2, 5]
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5).

Input: arr[] = [-1, -2, -3, -4]
Output: -1
Explanation: Max subarray sum is -1 of element (-1).

Input: arr[] = [5, 4, 7]
Output: 16
Explanation: Max subarray sum is 16 of elements (5, 4, 7) */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int maxSoFar = arr[0]; // Initialize to the first element
        int maxEndingHere = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]); // Max sum ending at current position
            maxSoFar = max(maxSoFar, maxEndingHere);             // Update overall max
        }

        return maxSoFar;
    }
};

int main()
{
    Solution obj;

    vector<int> arr1 = {1, 2, 3, -2, 5};
    cout << "Max subarray sum for arr1: " << obj.maxSubArray(arr1) << endl; // Output: 9

    vector<int> arr2 = {-1, -2, -3, -4};
    cout << "Max subarray sum for arr2: " << obj.maxSubArray(arr2) << endl; // Output: -1

    vector<int> arr3 = {5, 4, 7};
    cout << "Max subarray sum for arr3: " << obj.maxSubArray(arr3) << endl; // Output: 16

    return 0;
}