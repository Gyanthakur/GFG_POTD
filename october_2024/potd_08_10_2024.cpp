#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pairsum(vector<int> &arr)
    {
        int n = arr.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = arr[i] + arr[j];
                if (sum > maxSum)
                {
                    maxSum = sum;
                }
            }
        }
        return (maxSum == INT_MIN) ? -1 : maxSum;
    }
};

int main()
{
    int t;

    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}