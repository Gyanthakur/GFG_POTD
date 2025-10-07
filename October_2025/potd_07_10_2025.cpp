class Solution {
public:
    // Function to return the bottom view of the binary tree
    vector<int> bottomView(Node* root) {
        // If the tree is empty, return an empty list
        if (!root) return {};

        // Map to store horizontal distance -> node data
        // The bottom-most node for each horizontal distance will be stored
        map<int, int> mp;

        // Queue to perform level order traversal
        // Each element holds a node pointer and its horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        // Level order traversal (BFS)
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second; // Horizontal distance

            // The latest node at each horizontal distance (bottom-most)
            mp[hd] = node->data;

            // If the node has a left child, push it with hd - 1
            if (node->left) q.push({node->left, hd - 1});

            // If the node has a right child, push it with hd + 1
            if (node->right) q.push({node->right, hd + 1});
        }

        // Extract values from the map (ordered by horizontal distance)
        vector<int> ans;
        for (auto& p : mp) ans.push_back(p.second);

        return ans;
    }
};

/*
Time Complexity = O(n)
Space Complexity = O(n)
*/
