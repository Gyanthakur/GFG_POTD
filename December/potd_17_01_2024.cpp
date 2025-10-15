#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

class Solution
{
public:
    void solve(int n, vector<int> arr, vector<int> &ds, set<vector<int>> &ans, vector<bool> &vis)
    {
        // base case
        if (ds.size() == n)
        {
            ans.insert(ds);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                ds.push_back(arr[i]);
                solve(n, arr, ds, ans, vis);
                ds.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        vector<bool> vis(n, false);
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n, arr, ds, res, vis);

        for (auto it = res.begin(); it != res.end(); it++)
        {
            ans.push_back(*it);
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
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}