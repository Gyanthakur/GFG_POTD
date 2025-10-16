#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

vector<int> antiDiagonalPattern(vector<vector<int>> matrix)
{
    int n = matrix.size();
    queue<pair<int, int>> q;
    vector<int> at_diag;
    q.push({0, 0});
    while (!q.empty())
    {
        int node_i = q.front().first;
        int node_j = q.front().second;
        q.pop();
        at_diag.push_back(matrix[node_i][node_j]);

        if (node_j + 1 < n)
            q.push({node_i, node_j + 1});
        if (node_j == 0)
            if (node_i + 1 < n)
                q.push({node_i + 1, 0});
    }
    return at_diag;
}

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