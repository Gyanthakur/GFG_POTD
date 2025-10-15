#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    // with O(1) extra space.
    void arrange(long long arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] + (arr[arr[i]] % n) * n;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / n;
        }
        return;
    }
};