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
    int minDiff(Node *root, int K)
    {

        if (root == NULL)
            return INT_MAX;
        if (root->data == K)
            return 0;
        if (root->data > K)
            return min(root->data - K, minDiff(root->left, K));
        if (root->data < K)
            return min(K - root->data, minDiff(root->right, K));
    }
};