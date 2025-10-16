#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

int buyMaximumProducts(int n, int k, int price[])
{
    // Write your code here
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({price[i], i + 1});
    }
    int tot = 0;
    sort(vp.begin(), vp.end());
    for (auto it : vp)
    {
        int val = it.first;
        int num = it.second;
        int acc = k / val;
        int curr_price = val * min(num, acc);
        if (curr_price <= k)
        {
            k -= curr_price;
            tot += min(num, acc);
        }
    }
    return tot;
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