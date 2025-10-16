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
    Node *findtail(Node *root)
    {
        if (root == NULL)
            return NULL;
        if (root->right == NULL)
            return root;
        return findtail(root->right);
    }

    Node *findhead(Node *root)
    {
        if (root == NULL)
            return NULL;
        if (root->left == NULL)
            return root;
        return findhead(root->left);
    }

    Node *solve(Node *root)
    {
        if (root == NULL)
            return NULL;
        Node *lf = solve(root->left);
        Node *rt = solve(root->right);

        lf = findtail(lf);
        rt = findhead(rt);

        Node *crr = new Node(root->data);
        crr->data = root->data;
        crr->left = lf;
        crr->right = rt;

        if (lf != NULL)
            lf->right = crr;
        if (rt != NULL)
            rt->left = crr;

        return crr;
    }

    Node *bTreeToCList(Node *root)
    {
        // add code here.
        Node *temp = solve(root);
        Node *t1 = findhead(temp);
        Node *t2 = findtail(temp);
        t1->left = t2;
        t2->right = t1;
        return t1;
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