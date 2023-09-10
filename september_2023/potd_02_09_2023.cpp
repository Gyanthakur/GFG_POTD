#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
int getNode(Node *root, int k)
{
    queue<pair<Node *, int>> q;
    q.push({root, 1});
    int ans = 0;
    while (!q.empty())
    {
        Node *curr;
        int level;
        tie(curr, level) = q.front();
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, level + 1});
        if (curr->right != NULL)
            q.push({curr->right, level + 1});
        if (curr->left == NULL && curr->right == NULL)
        {
            if (level <= k)
            {
                ans++;
                k -= level;
            }
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string treestring;
        getline(cin,treestring);
        // Node *root = buildTree(treestring);
        int k;
        cin>>k;
        int res = getNode(treestring,k);
        cout<<res<<endl;

        
// 10 8 2 3 N 3 6 N N N 4
// 8

    }
    return 0;
}