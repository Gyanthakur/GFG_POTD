/*
GFG POTD - 29 Sep 2024

Problem Descrition:

You are given an array arr[] of positive integers and a threshold value k.
For each element in the array, divide it into the minimum number of small integers
such that each divided integer is less than or equal to k.
Compute the total number of these integer across all elements of the array.

Examples:

Input: k = 3, arr[] = [5, 8, 10, 13]
Output: 14
Explanation: Each number can be expressed as sum of different numbers less than or equal to k
as 5 (3 + 2), 8 (3 + 3 + 2), 10 (3 + 3 + 3 + 1), 13 (3 + 3 + 3 + 3 + 1).
So, the sum of count of each element is (2+3+4+5)=14.

*/

// Solution in C++

#include <bits/stdc++.h>

using namespace std;

int totalCount(int k, vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += arr[i] / k;
        if (arr[i] % k != 0 && arr[i] % k <= k)
            count++;
    }
    return count;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << totalCount(k, arr) << endl;
    return 0;
}