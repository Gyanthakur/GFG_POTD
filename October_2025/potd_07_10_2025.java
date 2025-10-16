
// POTD: Sort Colors
// URL: https://practice.geeksforgeeks.org/problems/sort-colors
// Github username: <BhuwanSKumar>
import java.util.Arrays;

public class potd_07_10_2025 {

    public static void sortColors(int[] nums) {
        int low = 0, mid = 0, high = nums.length - 1;

        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    int temp = nums[low];
                    nums[low] = nums[mid];
                    nums[mid] = temp;
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    int temp2 = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp2;
                    high--;
                    break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr1 = { 2, 0, 2, 1, 1, 0 };
        sortColors(arr1);
        System.out.println(Arrays.toString(arr1));

        int[] arr2 = {};
        sortColors(arr2);
        System.out.println(Arrays.toString(arr2));

        int[] arr3 = { 0, 0, 0 };
        sortColors(arr3);
        System.out.println(Arrays.toString(arr3));
    }
}