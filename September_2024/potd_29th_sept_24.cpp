#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalCount(int k, vector<int> &arr)
    {
        int total = 0;
        for (auto &x : arr)
        {
            total += (x + k - 1) / k;
        }
        return total;
    }
};

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        string ks;
        getline(cin, ks);
        while (ks.empty())
        {
            getline(cin, ks);
        }
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        while (input.empty())
        {
            getline(cin, input);
        }
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.totalCount(k, arr);
        cout << res << endl;
    }
    return 0;
}