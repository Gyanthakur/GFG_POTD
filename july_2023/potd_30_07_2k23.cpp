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
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        Node *successor = NULL; // 1
        while (root != NULL)    // 2
        {
            if (x->data >= root->data)
            {                       // 3
                root = root->right; // 4
            }
            else
            {                      // 5
                successor = root;  // 6
                root = root->left; // 7
            }
        }
        return successor;
    }
};