#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

// A N-ary Tree node
class Node
{
public:
    int data;
    vector<Node *> children;

    Node() {}

    Node(int val)
    {
        data = val;
    }

    Node(int val, vector<Node *> _children)
    {
        data = val;
        children = _children;
    }
};

int duplicateSubtreeNaryTree(Node *root)
{
    unordered_map<string, int> subtreeMap;
    constructSubtreeString(root, subtreeMap);
    int count = 0;
    for (auto it : subtreeMap)
    {
        if (it.second > 1)
        {
            count++;
        }
    }
    return count;
}

string constructSubtreeString(Node *node, unordered_map<string, int> &subtreeMap)
{
    string s = to_string(node->data) + ":";
    vector<string> childSubtrees;
    for (auto child : node->children)
    {
        childSubtrees.push_back(constructSubtreeString(child, subtreeMap));
    }
    sort(childSubtrees.begin(), childSubtrees.end());
    for (auto childSubtree : childSubtrees)
    {
        s += childSubtree + ",";
    }
    subtreeMap[s]++;
    return s;
}