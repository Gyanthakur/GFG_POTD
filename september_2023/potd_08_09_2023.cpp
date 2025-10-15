#include <bits/stdc++.h>
using namespace std;
#define int long long
long long t, a[100005];

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST(Node *root)
    {
        vector<int> values;

        function<void(Node *)> dfs = [&](Node *current)
        {
            if (current == nullptr)
                return;

            values.push_back(current->data);

            dfs(current->left);
            dfs(current->right);
        };

        dfs(root);
        sort(values.begin(), values.end(), greater<int>());

        function<void(Node *)> formation = [&](Node *current)
        {
            if (current == nullptr)
                return;

            formation(current->left);
            current->data = values.back();
            values.pop_back();
            formation(current->right);
        };

        formation(root);

        return root;
    }
};

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}