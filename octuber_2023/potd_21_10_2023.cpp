//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long power(long long x, int y, int p)
    {
        long long res = 1;
        while (y > 0)
        {

            if (y & 1)
                res = (res * x) % p;

            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    long long modInverse(long long n, int p)
    {
        return power(n, p - 2, p);
    }
    long long numberOfPaths(int M, int N)
    {
        long long path = 1, mod = 1e9 + 7;
        for (long long i = N; i < (M + N - 1); i++)
        {
            path = (path * i) % mod;
            long long inv = modInverse(i - N + 1, mod);
            path = (path * inv) % mod;
        }
        return path;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> M >> N;
        Solution ob;
        cout << ob.numberOfPaths(M, N) << endl;
    }
    return 0;
}
// } Driver Code Ends