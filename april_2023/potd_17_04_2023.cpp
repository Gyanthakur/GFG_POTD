#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        vector<pair<int, int>> v;
        vector<int> res(2, 0);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair(arr[i].profit, arr[i].dead));
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for (auto t : v)
        {
            int profit = t.first, deadline = t.second - 1;
            deadline = min(deadline, n);
            if (vis[deadline])
            {
                for (int i = deadline; i >= 0; i--)
                {
                    if (vis[i] == false)
                    {
                        res[0]++, res[1] += profit;
                        vis[i] = true;
                        break;
                    }
                }
            }
            else
            {
                res[0]++, res[1] += profit;
                vis[deadline] = true;
            }
        }
        return res;
    }
};