#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *pref(Node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->key > key)
        {
            return pref(root->left, key);
        }
        if (root->key < key)
        {
            Node *i = pref(root->right, key);
            if (!i)
            {
                return root;
            }
            return i;
        }
        return pref(root->left, key);
    }

    Node *succ(Node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->key > key)
        {
            Node *i = succ(root->left, key);
            if (!i)
            {
                return root;
            }
            return i;
        }
        if (root->key < key)
        {
            return succ(root->right, key);
        }
        return succ(root->right, key);
    }
    
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        pre = pref(root, key);
        suc = succ(root, key);
    }
};