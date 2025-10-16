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
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
    {
        sort(arr, arr + n);
        sort(brr, brr + m);
        int ans1 = arr[0], ans2 = arr[0];
        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int tm = x - arr[i];
            int left = 0, right = m - 1, mid;
            bool f = 0, f2 = 0;
            ;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if (brr[mid] == tm)
                {
                    ans1 = arr[i];
                    ans2 = brr[mid];
                    diff = 0;
                    f2 = 1;
                    break;
                }
                else if (brr[mid] > tm)
                {
                    if (diff > abs(brr[mid] + arr[i] - x))
                    {
                        ans1 = arr[i];
                        ans2 = brr[mid];
                        diff = abs(brr[mid] + arr[i] - x);
                    }
                    right = mid;
                }
                else
                {
                    if (diff > abs(brr[mid] + arr[i] - x))
                    {
                        ans1 = arr[i];
                        ans2 = brr[mid];
                        diff = abs(brr[mid] + arr[i] - x);
                    }
                    left = mid + 1;
                }
                if (f)
                    break;
                if (left == right)
                    f = 1;
            }
            if (f2)
                break;
        }
        vector<int> v;
        v.push_back(ans1);
        v.push_back(ans2);
        // cout<<ans1<<" "<<ans2<<endl;
        return v;
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