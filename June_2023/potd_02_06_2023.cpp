#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    vector<int> data;
    void precompute()
    {
        vector<bool> prime(1e6 + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i < 1e6 + 1; i++)
        {
            if (prime[i] == true)
            {
                data.push_back(i);
                int j = 2 * i;
                while (j < 1e6 + 1)
                {
                    prime[j] = false;
                    j = j + i;
                }
            }
        }
    }
    
    void dfs(int src, vector<vector<int>> &g, vector<bool> &visited, int &count)
    {

        visited[src] = true;
        count++;
        for (auto ele : g[src])
        {
            if (visited[ele] == false)
                dfs(ele, g, visited, count);
        }
    }

    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        int ans = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                int count = 0;
                dfs(i, g, visited, count);
                ans = max(ans, count);
            }
        }

        if (ans == 1)
            return -1;

        return data[ans - 1];
    }
};