#include <bits/stdc++.h>
using namespace std;

// structure of the node of the linked list is as
struct Node
{
    int data;
    Node *right, *down;

    Node(int x)
    {
        data = x;
        right = NULL;
        down = NULL;
    }
};

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution
{
public:
    Node *constructLinkedMatrix(vector<vector<int>> &mat)
    {
        if (mat.empty() || mat[0].empty())
        {
            return nullptr;
        }

        int rows = mat.size();
        int cols = mat[0].size();

        Node ***node = new Node **[rows];
        for (int i = 0; i < rows; i++)
        {
            node[i] = new Node *[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                node[i][j] = new Node(mat[i][j]);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (j < cols - 1)
                {
                    node[i][j]->right = node[i][j + 1];
                }
                if (i < rows - 1)
                {
                    node[i][j]->down = node[i + 1][j];
                }
            }
        }

        return node[0][0];
    }
};