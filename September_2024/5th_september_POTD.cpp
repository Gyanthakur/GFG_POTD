/*You are given an array arr of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation : All the numbers from 1 to 5 are present except 4.

Input: arr[] = [1]
Output: 2
Explanation: All the numbers from 1 to 2 are present except 2.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMissingNumber(vector<int> &arr)
    {
        int n = arr.size() + 1;            // Since one number is missing
        int expectedSum = n * (n + 1) / 2; // Sum of first n natural numbers
        int actualSum = 0;

        // Calculate the sum of elements in the array
        for (int num : arr)
        {
            actualSum += num;
        }

        // The missing number is the difference
        return expectedSum - actualSum;
    }
};

int main()
{
    Solution obj;
    vector<int> arr1 = {1, 2, 3, 5};
    cout << "Missing number in arr1: " << obj.findMissingNumber(arr1) << endl; // Output: 4

    vector<int> arr2 = {1};
    cout << "Missing number in arr2: " << obj.findMissingNumber(arr2) << endl; // Output: 2

    return 0;
}