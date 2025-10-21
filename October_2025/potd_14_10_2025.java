/*
 * Problem: Sum of Nodes in BST Range
 * Time Complexity: O(n)
 * Space Complexity: O(H) //H is tree height
 */

class Solution {
    public int nodeSum(Node root, int l, int r) {

        if (root == null) return 0;

        if (root.data < l) {
            return nodeSum(root.right, l, r);
        }
        else if (root.data > r) {
            return nodeSum(root.left, l, r);
        }
        int left = nodeSum(root.left, l, r);
        int right = nodeSum(root.right, l, r);

        return left + right + root.data;
    }
}
