#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumInteger(long long N, vector<int> &A)
    {
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
        }
        sort(A.begin(), A.end());

        for (int i = 0; i < N; i++)
        {
            int mini = A[i];
            if (sum <= N * mini)
            {
                return A[i];
            }
        }
    }
};