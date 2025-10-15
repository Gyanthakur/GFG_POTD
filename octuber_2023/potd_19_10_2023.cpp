// { Driver Code Starts
#include <bits/stdc++.h>	
using namespace std;
// } Driver Code Ends

class Solution
{
public:
	// Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x)
	{
		// code here
		int count = 0;
		queue<int> q;
		q.push(0);
		vector<bool> vis(v, false);
		vis[0] = true;
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				int a = q.front();
				q.pop();
				if (a == x)
					return count;
				for (auto i : adj[a])
				{
					if (!vis[i])
					{
						vis[i] = true;
						q.push(i);
					}
				}
			}
			count++;
		}
		return -1;
	}
};