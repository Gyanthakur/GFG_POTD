// File: october_2025/potd_11_10_2025.java
public class potd_11_10_2025 {

    // Method to find the largest element in an array
    public static int findLargest(int[] arr) {
        if (arr == null || arr.length == 0) {
            throw new IllegalArgumentException("Array is empty or null");
        }

        int max = arr[0]; // Initialize with first element
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i]; // Update if current element is larger
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] arr1 = {4, 7, 1, 9, 3};
        System.out.println("Array: " + java.util.Arrays.toString(arr1));
        System.out.println("Largest Element: " + findLargest(arr1));

        int[] arr2 = {-5, -2, -10, -1};
        System.out.println("Array: " + java.util.Arrays.toString(arr2));
        System.out.println("Largest Element: " + findLargest(arr2));
    }
}
