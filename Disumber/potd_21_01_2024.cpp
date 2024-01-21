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
private:
    vector<vector<int>> adj;
    bool isPossible(int n, int m, int mid) {
        int set = (1 << mid) - 1;
        int limit = (1 << n);
        while (set < limit) {
            bool vis[n + 1][n + 1] = {0};
            int edgeCovered = 0;
            for (int j = 1, u = 1; j < limit; j = j << 1, u++) {
                if (set & j) {
                    for (int v = 1; v <= n; v++) {
                        if (adj[u][v] && !vis[u][v]) {
                            edgeCovered++;
                            vis[u][v] = 1;
                            vis[v][u] = 1;
                        }
                    }
                }
            }
            if (edgeCovered == m)
                return true;
            int rightMostSetBit = set & -set;
            int val = set + rightMostSetBit;
            set = (((val ^ set) >> 2) / rightMostSetBit) | val;
        }
        return false;
    }
public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int m = edges.size();
        adj.resize(n + 1, vector<int>(n + 1));
        for (auto v : edges) {
            adj[v.first][v.second] = 1;
            adj[v.second][v.first] = 1;
        }
        int ans = 1, r = n;
        while (ans < r) {
            int mid = (ans + r) >> 1;
            if (isPossible(n, m, mid)) {
                r = mid;
            } else {
                ans = mid + 1;
            }
        }
        return ans;
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