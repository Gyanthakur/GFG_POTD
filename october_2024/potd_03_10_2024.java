//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class potd_03_10_2024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            int[] nums = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                nums[i] = Integer.parseInt(parts[i]);
            }
            Solution ob = new Solution();
            int[] ans = ob.findMajority(nums);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}

// } Driver Code Ends

class Solution {
    // Function to find the majority elements in the array
    public int[] findMajority(int[] nums) {
        // Your code goes here.
        int n = nums.length;
        int num1 = 0, num2 = 0, c1 = 0, c2 = 0;
        int[] res = new int[2]; // Assume max two majority elements
        int resSize = 0; // To track actual size of result

        // Finding the two most frequent numbers using Boyer-Moore algorithm
        for (int x : nums) {
            if (x == num1) {
                c1++;
            } else if (x == num2) {
                c2++;
            } else if (c1 == 0) {
                num1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                num2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        // Counting the occurrences of num1 and num2
        for (int x : nums) {
            if (x == num1) {
                c1++;
            } else if (x == num2) {
                c2++;
            }
        }

        // Checking if num1 and num2 are majority elements
        if (c1 > n / 3)
            res[resSize++] = num1;
        if (c2 > n / 3)
            res[resSize++] = num2;

        // Handling no majority element case
        if (resSize == 0) {
            return new int[] { -1 };
        }

        // Returning the actual result
        return Arrays.copyOf(res, resSize);
    }
}