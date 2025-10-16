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
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;
        if (r1 == NULL || r2 == NULL || (r1->data != r2->data))
            return false;
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
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