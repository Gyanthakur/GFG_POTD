#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            v[i] = i;
        }
        for (int i = 2; i * i <= n; i++)
        {
            if (v[i] == i)
            {
                for (int j = i; j <= n; j += i)
                {
                    if (v[j] == j)
                        v[j] = i;
                }
            }
        }
        return v;
    }
};