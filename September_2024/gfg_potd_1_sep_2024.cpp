// 👉🏻 Q.calculate the maximum path sum from two given arrays, arr1 and arr2
// You can switch between the arrays at common elements to maximize the sum of the path taken. 
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        // CodeGenius
        int m = arr1.size();
        int n = arr2.size();
        int s1 = 0, s2 = 0;
        int i = 0, j = 0;
        int ans = 0;

        while (i < m && j < n)
        {
            if (arr1[i] == arr2[j])
            {
                ans += max(s1, s2) + arr1[i];
                i++, j++;
                s1 = 0;
                s2 = 0;
            }
            else if (arr1[i] < arr2[j])
                s1 += arr1[i++];
            else
                s2 += arr2[j++];
        }
        while (i < m)
            s1 += arr1[i++];
        while (j < n)
            s2 += arr2[j++];

        ans += max(s1, s2);
        return ans;
    }
};

// 👉🏻time complexity of the algorithm is: O(m + n). a

// 👉🏻The space complexity is O(1)-function uses  constant amount of extra space regardless of the size of the input arrays.

// 👉🏻Logic of the Code-
// A.The goal is to traverse both arrays from start to end, and you can either:

// 1.Move along one array until the values match.
// 2.Switch between arrays when the same value appears in both arrays.
// B.At any matching value in both arrays, you choose the maximum sum accumulated from both arrays and continue the process. This helps ensure that the maximum possible sum is collected.