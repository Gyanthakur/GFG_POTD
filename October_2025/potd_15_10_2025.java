/*
 * Problem: k-th Smallest in BST
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
    
    static int kthSmallestRecur(Node root, int[] cnt, int k) {
        if (root == null) return -1;
        
        int left = kthSmallestRecur(root.left, cnt, k);

        if (left != -1) return left;
        
        cnt[0]++;
        
        if (cnt[0] == k) return root.data;
        
        int right = kthSmallestRecur(root.right, cnt, k);
        return right;
    }
    
    
    public int kthSmallest(Node root, int k) {
        int[] cnt = {0};
        return kthSmallestRecur(root, cnt, k);
    }
}
