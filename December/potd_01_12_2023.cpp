#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

struct Node
{
    int data;
    Node *right, *left;
};

class Solution
{
public:
    bool isDeadEnd(Node *root)
    {
        queue<Node *> q;
        vector<int> leaf;
        vector<int> visited;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            visited.push_back(node->data);
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            if (node->left == NULL && node->right == NULL)
                leaf.push_back(node->data);
        }

        int n = leaf.size();
        for (int i = 0; i < n; i++)
        {
            if ((leaf[i] == 1 && find(visited.begin(), visited.end(), 2) != visited.end()) || (find(visited.begin(), visited.end(), leaf[i] - 1) != visited.end() && find(visited.begin(), visited.end(), leaf[i] + 1) != visited.end()))
                return true;
        }

        return false;
    }
};

void solution()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}