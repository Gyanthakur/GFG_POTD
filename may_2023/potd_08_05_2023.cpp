#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int modulo(string s, int m)
    {
        // code here

        int mul = 1;
        int ans = 0;

        int j = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            mul = mul % m;

            ans += mul * (s[i] == '1' ? 1 : 0);
            ans %= m;

            mul *= 2;
        }
        return ans;
    }
};