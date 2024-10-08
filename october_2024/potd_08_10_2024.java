


class Solution {
    public static int pairsum(int[] arr) {
        // code here
        Arrays.sort(arr);
        return arr[arr.length-1] + arr[arr.length-2];
    }
}
