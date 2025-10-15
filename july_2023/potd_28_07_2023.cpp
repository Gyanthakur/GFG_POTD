#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
struct Node
{
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
    Node *LCA(Node *root, int n1, int n2)
    {
        if (!root)
            return root;
        if (n1 < root->data and n2 < root->data)
            return LCA(root->left, n1, n2);
        if (n1 > root->data and n2 > root->data)
            return LCA(root->right, n1, n2);
        return root;
    }
};