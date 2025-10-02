class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        // code here
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        backtrack(1, new ArrayList<>(), 0, k, n, result);
        return result;
    }
    
    private void backtrack(int start, ArrayList<Integer> current, int sum, int k, int n, ArrayList<ArrayList<Integer>> result) {
        if (current.size() == k) {
            if (sum == n) {
                result.add(new ArrayList<>(current));
            }
            return;
        }
        
        for (int i = start; i <= 9; i++) {
            if (sum + i > n) {
                break; // Prune the branch if sum exceeds n
            }
            current.add(i);
            backtrack(i + 1, current, sum + i, k, n, result);
            current.remove(current.size() - 1);
        }
    }
}

