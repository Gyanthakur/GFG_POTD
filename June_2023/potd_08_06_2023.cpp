#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            v[i] = i + 1;
        k--;
        vector<int> kthP(n, 0);
        vector<int> fact(n, 1);

        for (int i = 2; i < n; i++)
        {
            int f = fact[i];
            fact[i] = fact[i - 1] * i;
        }

        int i = 0;
        while (k > 0)
        {
            int f = fact[v.size() - 1];
            int ind = k / f;
            kthP[i] = v[ind];
            k %= f;
            v.erase(v.begin() + ind);
            i++;
        }

        int j = 0;
        while (i < n)
        {
            kthP[i] = v[j];
            i++, j++;
        }

        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += to_string(kthP[i]);
        }

        return ans;
    }
};