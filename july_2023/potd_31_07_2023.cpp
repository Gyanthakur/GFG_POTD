#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        // first make container and visited.
        vector<int> bfs;
        vector<int> visit(V, 0);

        // second make Queue and push zero in queue first
        queue<int> q;
        q.push(0);
        // also make visited.
        visit[0] = 1;

        // make loop and run until queue run out.
        while (!q.empty())
        {
            // take first element in queue stored and make queue empty.
            int value = q.front();
            q.pop();

            // take this value in bfs container
            bfs.push_back(value);

            // check in loop value is visited or not
            for (auto it : adj[value])
            {
                // if value is not visited then visit this value and push in queue also
                if (!visit[it])
                {
                    q.push(it);
                    visit[it] = 1;
                }
            }
        }
        return bfs;
    }
};