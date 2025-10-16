#include <bits/stdc++.h>
using namespace std;

int main()
{
  return 0;
}

struct Node
{
  int data;
  struct Node *left, *right;
  // contructor
  Node(int val) : data(val), left(NULL), right(NULL) {}
};

// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the
// new binary tree formed
class Solution
{
public:
  Node *solve(int pre[], int &index, unordered_map<int, int> &m, int &size)
  {
    if (index == size)
      return NULL;
    int ele = pre[index];
    Node *root = new Node(ele);
    if (index + 1 < size)
    {
      int next = pre[index + 1];
      if (m[next] < m[ele])
      {
        return root;
      }
      index++;
      root->left = solve(pre, index, m, size);
      index++;
      root->right = solve(pre, index, m, size);
    }
    return root;
  }

  Node *constructBinaryTree(int pre[], int preMirror[], int size)
  {
    // Code here
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
    {
      m[preMirror[i]] = i;
    }
    int index = 0;
    return solve(pre, index, m, size);
  }
};