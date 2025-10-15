#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

// class Solution {
//   public:
//     // O(n) - Time
//     // O(n) - space
//     // DP Solution
//     long long countBits(long long N) {
//         vector<int> setBitCount(N + 1, 0);
//         long long res = 0;

//         for(long long i = 1; i <= N; i++) {

//             // odd case
//             if(i & 1)
//                 setBitCount[i] = setBitCount[i >> 1] + 1;

//             // even case
//             else
//                 setBitCount[i] = setBitCount[i >> 1];

//             // storing count
//             res += setBitCount[i];

//         }

//         return res;
//     }
// };

class Solution
{
public:
    long long countBits(long long N)
    {
        long long ans = 0;

        int a = 1;
        int b = 1 << a;

        for (int i = 0; i < 31; i++)
        {

            ans += (N / b) * a;
            int rem = (N % b) - a + 1;

            if (rem > 0)
                ans += rem;

            a <<= 1;
            b <<= 1;
        }
        return ans;
    }
};