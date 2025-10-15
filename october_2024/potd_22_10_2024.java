/*
Problem:
Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

Example:
Input: arr[] = [1, 2, 1] , x= 1 , y = 2
Output: 2
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1, 2], x and y have same occurrence(1).
2) [2, 1], x and y have same occurrence(1).

*/

import java.util.HashMap;

public class potd_22_10_2024 {
    public static int countEqualOccurrences(int[] arr, int x, int y) {
        // HashMap to store the frequency of count differences.
        HashMap<Integer, Integer> countMap = new HashMap<>();
        int countDiff = 0; // Tracks the difference between counts of x and y.
        int result = 0; // Stores the number of valid subarrays.

        // Initialize the map with countDiff 0 (initial state).
        countMap.put(0, 1);

        // Traverse the array and update the count difference.
        for (int num : arr) {
            if (num == x) {
                countDiff++; // Increment if the element is x.
            } else if (num == y) {
                countDiff--; // Decrement if the element is y.
            }

            // If this countDiff was seen before, it means there's a valid subarray.
            result += countMap.getOrDefault(countDiff, 0);

            // Update the frequency of the current countDiff in the map.
            countMap.put(countDiff, countMap.getOrDefault(countDiff, 0) + 1);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 1 };
        int x = 1, y = 2;

        int result = countEqualOccurrences(arr, x, y);
        System.out.println("Number of subarrays with equal occurrences of " + x + " and " + y + ": " + result);
    }
}