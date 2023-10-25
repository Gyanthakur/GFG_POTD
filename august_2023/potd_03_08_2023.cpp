#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution {
  public:
    void dfs(int node,vector<vector<pair<int,int>>> &adj,stack<int> &s,vector<int> &visited){
        if(visited[node]!=1){
            visited[node]=1;
            for(int i=0;i<adj[node].size();i++){
                dfs(adj[node][i].first,adj,s,visited);
            }
            s.push(node);
        }
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){

        vector<vector<pair<int,int>>> adj(N);
        vector<int> dist(N,1e9);
        stack<int> s;
        vector<int> visited(N,0);
        dist[0]=0;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        for(int i=0;i<adj.size();i++){
            if(visited[i]==0){
                dfs(i,adj,s,visited);
            }
        }
        while(!s.empty()){
            for(int i=0;i<adj[s.top()].size();i++){
                dist[adj[s.top()][i].first]=min(dist[adj[s.top()][i].first],dist[s.top()]+adj[s.top()][i].second);
            }
            s.pop();
        }
        
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
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
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}