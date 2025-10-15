#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int LargButMinFreq(int arr[], int n)
    {
        // code here

        unordered_map<int, int> container;

        for (int i = 0; i < n; i++)
        {
            container[arr[i]]++;
        }

        int frequency = INT_MAX;
        int number = 0;

        for (auto el : container)
        {
            if (el.second < frequency)
            {
                number = el.first;
                frequency = el.second;
            }
            else if (el.second == frequency && el.first > number)
            {
                number = el.first;
            }
        }

        return number;
    }
};