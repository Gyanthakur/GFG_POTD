import java.util.*;

class Solution {
    public int getSingle(int[] arr) {
        // Using XOR to find the number occurring an odd number of times
        int result = 0;
        for (int num : arr) {
            result ^= num;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());
        
        while (t-- > 0) {
            String input = scanner.nextLine();
            String[] parts = input.split(" ");
            int[] arr = new int[parts.length];
            
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }

            Solution obj = new Solution();
            int res = obj.getSingle(arr);
            System.out.println(res);
        }
        
        scanner.close();
    }
}
