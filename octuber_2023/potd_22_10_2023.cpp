#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>
using namespace std;
long long t;

class Solution
{
public:
    long long int MOD = 1000000007;

    long modInverse(long base)
    {
        return power(base, MOD - 2);
    }

    long power(long base, int exponent)
    {
        long result = 1;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }

    int nCk(int n, int k)
    {
        long numerator = 1;
        long denominator = 1;

        for (int i = 0; i < k; i++)
        {
            numerator = (numerator * (n - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }
        return (int)((numerator * modInverse(denominator)) % MOD);
    }

    long long numberOfPaths(int M, int N)
    {
        return nCk(M + N - 2, M - 1);
    }
};

void solution()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}