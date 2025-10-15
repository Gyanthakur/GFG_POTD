#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    void topo(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                topo(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    vector<int> topoSort(int N, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                topo(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};