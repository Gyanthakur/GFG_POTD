#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

vector<string> winner(string arr[], int n)
{
    unordered_map<string, int> m;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] += 1;
        mx = max(mx, m[arr[i]]);
    }
    vector<string> p;
    for (auto a : m)
    {
        if (mx == a.second)
            p.push_back(a.first);
    }
    sort(p.begin(), p.end());
    return {p[0], to_string(mx)};
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