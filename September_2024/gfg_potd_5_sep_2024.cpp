// 👉🏻 Q.You are given an array arr of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.
//  From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {

        long long expectedSum = n * (n + 1) / 2; // Expected sum of the first n natural numbers
        long long actualSum = 0;

        // Calculate the sum of elements in the array
        for (int i = 0; i < arr.size(); i++)
        {
            actualSum += arr[i];
        }

        // The missing number is the difference between the expected and actual sums
        return int(expectedSum - actualSum);
    }
};

// 👉🏻logic of code
//  The code finds the missing number in an array containing n-1 distinct integers from 1 to n. It calculates the expected sum of the first n natural numbers using the formula n(n+1)/2.
//  then subtracts the actual sum of the array elements from the expected sum. The difference between these sums is the missing number.

// 👉🏻  Time Complexity (TC):
// O(n):
// Calculating the sum of all elements in the array arr takes O(n-1) time, which simplifies to O(n).
// The formula for the sum of the first n natural numbers runs in constant time O(1).
// Thus, the overall time complexity is O(n).

// 👉🏻Space Complexity (SC):
// O(1):
// The algorithm uses only a few extra variables (sum, sum2) and doesn't use any additional space that grows with the input size.
// The input vector arr is not considered part of the space complexity since it's provided as input.