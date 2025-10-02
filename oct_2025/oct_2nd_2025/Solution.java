package GFG_POTD.oct_2025.oct_2nd_2025;
import java.util.*;
class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(1, k, n, new ArrayList<>(), result);
        return result;
    }

    public void backtrack(int start, int k, int target, ArrayList<Integer> path, ArrayList<ArrayList<Integer>> result) {
        if (k == 0 && target == 0) {
            result.add(new ArrayList<>(path));
            return;
        }
        if (k == 0 || target < 0) return;

        for (int i = start; i <= 9; i++) {
            path.add(i);
            backtrack(i + 1, k - 1, target - i, path, result);
            path.remove(path.size() - 1);
        }
    }
}
