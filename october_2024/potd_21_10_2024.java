/*
Problem:
Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two non-empty subsets such that the XOR of elements of each group is equal. Each element should belong to exactly one subset.
Note:
The answer could be very large so print it by doing modulo with 109 + 7. 
Subsets with the same elements but derived from different indices are different.

Example:
Input : arr[] = [1, 2, 3]
Output : 3
Explanation: {(1),(2, 3)}, {(2),(1, 3)}, {(3),(1, 2)} are three ways with equal XOR value of two groups.

*/

import java.util.*;

public class EqualXORSubsets {

    static final int MOD = 1_000_000_007;

    // Function to calculate (base^exp) % MOD using modular exponentiation.
    static long modPow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) { // If exp is odd, multiply the result with base.
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base.
            exp >>= 1; // Divide exp by 2.
        }
        return result;
    }

    // Function to count the number of ways to split the array.
    static int countWays(int[] arr) {
        int totalXOR = 0;

        // Calculate the XOR of all elements in the array.
        for (int num : arr) {
            totalXOR ^= num;
        }

        // If the total XOR is not zero, no valid split is possible.
        if (totalXOR != 0) {
            return 0;
        }

        int n = arr.length;

        // Calculate (2^(n-1) - 1) % MOD.
        long ways = modPow(2, n - 1, MOD) - 1;
        if (ways < 0) {
            ways += MOD; // Ensure the result is non-negative.
        }

        return (int) ways;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        int result = countWays(arr);
        System.out.println("Number of ways to split the array: " + result);
    }
}


