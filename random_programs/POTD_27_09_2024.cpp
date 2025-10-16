#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        int max_steps = 0;     // To store the maximum steps
        int current_steps = 0; // To store the current consecutive steps

        // Traverse the array from the second element
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                current_steps++; // Increase steps if current building is taller
            }
            else
            {
                // Update max_steps if the current sequence ends
                max_steps = max(max_steps, current_steps);
                current_steps = 0; // Reset for the next sequence
            }
        }

        // Compare the last sequence of steps
        max_steps = max(max_steps, current_steps);

        return max_steps;
    }
};