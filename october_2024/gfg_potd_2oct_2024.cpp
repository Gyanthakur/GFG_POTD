/* GFG POTD - 2/10/2024

Problem -
Given an array arr integers. Do the following operation until a single element left. For every kth operation:

Right, rotate the vector clockwise by 1.
Delete the kth element from the last.
Now, find the element which is left at last.

Input: arr = [1, 2, 3, 4, 5, 6]
Output: 3
Explanation: Rotate the vector clockwise i.e. after rotation the vector arr = [6, 1, 2, 3, 4, 5]
and delete the last element that is 5 that will be arr = [6, 1, 2, 3, 4]. Similarly, the output will be 3

*/

// Solution in C++

#include <bits/stdc++.h>

using namespace std;

int rotateDelete(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (n & 1)
        n += 3;
    int in = (n + 3) / 4;
    return arr[in];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << rotateDelete(arr) << endl;
    return 0;
}