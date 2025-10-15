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
    struct Node *left, *right;
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    Node *parent(Node *root, int target)
    {
        Node *t;
        if (!root)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == target)
                t = temp;
            if (temp->left)
            {
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            if (temp->right)
            {
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
        return t;
    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        Node *t = parent(root, target);
        unordered_set<Node *> s;
        queue<Node *> q;
        q.push(t);
        int level = 0;
        while (!q.empty() && level <= k)
        {
            int sz = q.size();
            if (level == k)
            {
                vector<int> ans;
                for (int i = 0; i < sz; i++)
                {
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                sort(ans.begin(), ans.end());
                return ans;
            }
            else
            {
                for (int i = 0; i < sz; i++)
                {
                    Node *temp = q.front();
                    q.pop();
                    if (s.find(temp) == s.end())
                    {
                        s.insert(temp);
                    }
                    if (temp->left && s.find(temp->left) == s.end())
                    {
                        q.push(temp->left);
                    }
                    if (temp->right && s.find(temp->right) == s.end())
                    {
                        q.push(temp->right);
                    }
                    if (mp[temp] && s.find(mp[temp]) == s.end())
                    {
                        q.push(mp[temp]);
                    }
                }
            }
            level++;
        }
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