#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    // Function to do inorder traversal and store the result
    void inorder(Node *root, vector<int> &in)
    {
        if (root == NULL)
            return;

        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }

    // Function to find the nodes that are common in both BSTs
    vector<int> findCommon(Node *root1, Node *root2)
    {
        vector<int> in1, in2;
        inorder(root1, in1);
        inorder(root2, in2);

        vector<int> ans;
        map<int, int> m;

        for (int x : in1)
            m[x]++;

        for (int x : in2)
            m[x]++;

        for (auto &p : m)
        {
            if (p.second == 2)
                ans.push_back(p.first);
        }

        return ans;
    }
};