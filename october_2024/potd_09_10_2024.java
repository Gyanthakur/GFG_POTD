class Solution {
    static Node construct(int arr[][]) {
        if (arr.length == 0 || arr[0].length == 0) return null;
        int n = arr.length;
        Node[][] nodes = new Node[n][n];

      // Creating Nodes of every Array element.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nodes[i][j] = new Node(arr[i][j]);
            }
        }

      // Combining the Nodes in 2D Matrix using right and down pointer.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n) {
                    nodes[i][j].right = nodes[i][j + 1];
                }
                if (i + 1 < n) {
                    nodes[i][j].down = nodes[i + 1][j];
                }
            }
        }

        return nodes[0][0];
    }
}
