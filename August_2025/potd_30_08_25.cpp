/*
Date: 30 August 2025
Problem: The Celebrity Problem
Platform: GeeksforGeeks (POTD)
Approach: Two-pass elimination method
Time Complexity: O(n)
Space Complexity: O(1)

Explanation:
A celebrity is someone who is known by everyone but knows no one.
We first find a potential celebrity by eliminating impossible candidates,
then verify if that candidate truly fits the definition.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int candidate = 0;
        // Step 1: Find the potential celebrity
        for (int i = 1; i < n; i++)
        {
            if (mat[candidate][i] == 1)
            {
                candidate = i;
            }
        }
        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++)
        {
            if (i == candidate)
                continue;
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
            {
                return -1; // Not a celebrity
            }
        }
        return candidate;
    }
};