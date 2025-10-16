#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findTriplet(vector<int> &arr)
    {
        // Your code
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if ((arr[i] + arr[j] == arr[k]) || (arr[i] + arr[k] == arr[j]) || (arr[j] + arr[k] == arr[i]))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};