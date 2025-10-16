#include <bits/stdc++.h>
using namespace std;

class Node // class to create a node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isBst(Node *root, int &prev, int &sum, int &cnt)
    {
        if (root == NULL)
        {
            return true;
        }
        if (!isBst(root->left, prev, sum, cnt))
        {
            return false;
        }
        if (prev >= root->data)
        {
            return false;
        }
        sum += root->data;
        cnt++;
        prev = root->data;
        return isBst(root->right, prev, sum, cnt);
        return true;
    }

    void dfs(Node *root, int target, int &ans)
    {
        if (root == NULL)
        {
            return;
        }
        int sum = 0;
        int cnt = 0;
        int prev = -1;
        if (isBst(root, prev, sum, cnt))
        {
            if (sum == target)
            {
                ans = min(ans, cnt);
            }
        }
        dfs(root->left, target, ans);

        dfs(root->right, target, ans);
    }

    int minSubtreeSumBST(int target, Node *root)
    {
        // code here
        int ans = INT_MAX;
        dfs(root, target, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};