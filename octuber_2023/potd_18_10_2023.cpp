class Solution {
  public:
    bool check(int node, vector<int> adj[], vector<int> &vis)
    {
        if(vis[node]) return false;
        vis[node] = 1;
        for(auto i : adj[node])
        {
            if(check(i,adj,vis) == false) return false;
        }
        vis[node] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i = 0; i < V; i++)
        {
            if(check(i,adj,vis)) ans.push_back(i);
        }
        return ans;
    }
};