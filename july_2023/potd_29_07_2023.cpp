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

// your task is to complete the Function
// Function should return median of the BST
void inorder(struct Node *root, vector<float> &vec)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

float findMedian(struct Node *root)
{
    // Code here
    vector<float> vec;
    inorder(root, vec);
    int n = vec.size();
    if (n % 2 == 0)
    {
        return ((vec[n / 2] + vec[n / 2 - 1]) / 2);
    }
    else
    {
        return vec[n / 2];
    }
}