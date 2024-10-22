import java.util.HashMap;

class Solution {
    static int countSubarrays(int[] arr, int x, int y) {
        HashMap<Integer, Integer> countMap = new HashMap<>();
        countMap.put(0, 1); 
        
        int countX = 0, countY = 0, result = 0;

        for (int num : arr) {
    
            if (num == x) {
                countX++;
            } else if (num == y) {
                countY++;
            }

            int difference = countX - countY;
            result += countMap.getOrDefault(difference, 0);
            countMap.put(difference, countMap.getOrDefault(difference, 0) + 1);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 1};
        System.out.println(countSubarrays(arr1, 1, 2)); // Output: 2

        int[] arr2 = {1, 2, 1};
        System.out.println(countSubarrays(arr2, 4, 6)); // Output: 6

        int[] arr3 = {1, 2, 1};
        System.out.println(countSubarrays(arr3, 1, 4)); // Output: 1
    }
}
