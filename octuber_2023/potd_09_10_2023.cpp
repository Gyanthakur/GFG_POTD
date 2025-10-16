#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        if (node == NULL)
            return 0;

        int leftAns = height(node->left);
        int rightAns = height(node->right);
        int ans = max(leftAns, rightAns) + 1;
        return ans;
    }
};

long long t;
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