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
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                int lo = j + 1, hi = arr.size() - 1;
                while (lo < hi)
                {
                    int sum = arr[i] + arr[lo] + arr[j] + arr[hi];

                    if (sum < k)
                    {
                        lo++;
                    }
                    else if (sum > k)
                    {
                        hi--;
                    }
                    else
                    {
                        ans.push_back({arr[i], arr[j], arr[lo], arr[hi]});
                        lo++;
                        hi--;
                    }
                }
            }
        }
        set<vector<int>> s;
        for (auto &vec : ans)
        {
            s.insert(vec);
        }
        vector<vector<int>> ans1;
        for (auto vec : s)
        {
            ans1.push_back(vec);
        }
        return ans1;
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