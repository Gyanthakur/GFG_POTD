/*
 * Problem: Maximum Sum of Smallest and Second Smallest Elements in Subarrays
 * 
 * Given an array of integers, find the maximum sum of the smallest and second 
 * smallest element among all possible subarrays of size greater than one.
 * 
 * Optimized Approach - O(n^2) Time, O(1) Space  
 * - For each starting position, maintain two smallest elements as we extend
 * - Update first and second smallest efficiently without sorting
 * - Calculate sum for each valid subarray
 * 
 * Edge Cases:
 * - Array size < 2: Return -1
 * - All elements same: Any subarray gives same sum
 * - Single element: No valid subarrays
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * Optimized Approach
     * Time Complexity: O(n^2) - O(n^2) for nested loops, constant work inside
     * Space Complexity: O(1) - only using constant extra space
     * 
     * Algorithm:
     * 1. For each starting position i, maintain running smallest and second smallest
     * 2. As we extend the subarray by adding elements, efficiently update these values
     * 3. For each valid subarray [i...j], calculate sum of two smallest elements
     * 4. Track maximum sum across all subarrays
     * 
     * Key Insight: Instead of sorting each subarray, we maintain the two smallest
     * elements incrementally as we build the subarray from left to right.
     */
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: array with less than 2 elements
        if (n < 2) return -1;
        
        int maxSum = INT_MIN;
        
        // For each starting position i
        for (int i = 0; i < n; i++) {
            int first = arr[i];   // smallest element so far in current subarray
            int second = INT_MAX; // second smallest element so far in current subarray
            
            // Extend the subarray from position i to j
            for (int j = i + 1; j < n; j++) {
                // Efficiently update the two smallest elements
                // Case 1: New element is smaller than current smallest
                if (arr[j] < first) {
                    second = first;  // Previous smallest becomes second smallest
                    first = arr[j];  // New element becomes smallest
                } 
                // Case 2: New element is between first and second smallest
                else if (arr[j] < second) {
                    second = arr[j]; // New element becomes second smallest
                }
                
                // Current subarray is arr[i...j] with size (j-i+1) >= 2
                // Calculate sum of two smallest elements in this subarray
                int currentSum = first + second;
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};
