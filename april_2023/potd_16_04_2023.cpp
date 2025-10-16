#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(int N, vector<int> &A, vector<int> &B)
    {
        vector<int> AEvenOdd[2], BEvenOdd[2];

        long long sum1 = 0, sum2 = 0;

        for (int i = 0; i < N; ++i)
        {
            sum1 += A[i];
            sum2 += B[i];

            if (abs(A[i]) % 2 == 0)
                AEvenOdd[0].push_back(A[i]);
            else
                AEvenOdd[1].push_back(A[i]);

            if (abs(B[i]) % 2 == 0)
                BEvenOdd[0].push_back(B[i]);
            else
                BEvenOdd[1].push_back(B[i]);
        }

        if (sum1 != sum2 || (AEvenOdd[0].size() != BEvenOdd[0].size()))
            return -1;

        long long ans = 0;

        for (int i = 0; i < 2; ++i)
        {
            sort(AEvenOdd[i].begin(), AEvenOdd[i].end());
            sort(BEvenOdd[i].begin(), BEvenOdd[i].end());

            for (int j = 0; j < AEvenOdd[i].size(); ++j)
            {
                ans += abs(AEvenOdd[i][j] - BEvenOdd[i][j]) / 2;
            }
        }
        return ans / 2;
    }
};