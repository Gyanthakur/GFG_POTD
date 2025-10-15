#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

class UnionFind
{
private:
    vector<int> parent;

public:
    UnionFind(int size)
    {
        for (int i{}; i < size; i++)
        {
            parent.push_back(i);
        }
    }

    // find
    int find(int i)
    {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i]);
    }

    // union
    void join(int i, int j)
    {
        int parent_i = this->find(i), parent_j = this->find(j);
        int minimum = min(parent_i, parent_j), maximum = max(parent_i, parent_j);

        parent[minimum] = maximum;
    }
};

class Solution
{
public:
    int detectCycle(int V, vector<int> adj[])
    {
        UnionFind uf(V);

        for (int node{}; node < V; node++)
        {
            for (int child : adj[node])
            {
                if (node < child)
                {
                    if (uf.find(node) == uf.find(child))
                        return 1;
                    else
                        uf.join(node, child);
                }
            }
        }

        return 0;
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