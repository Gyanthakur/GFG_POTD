#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int minimumSum(string s)
    {
        int n = s.size();
        int i, j;
        if (n % 2 == 0)
        {
            i = n / 2 - 1;
            j = n / 2;
        }
        else
        {
            i = n / 2;
            j = n / 2;
        }
        char prev = '#';
        int ans{};
        while (i >= 0)
        {
            if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1])
                return -1;
            else if (s[i] == '?' && s[j] == '?')
            {
                i--;
                j++;
                continue;
            }
            else if (s[i] != '?' && s[i] != prev)
            {
                if (prev != '#')
                    ans += 2 * abs(s[i] - prev);
                prev = s[i];
            }
            else if (s[j] != '?' && s[j] != prev)
            {
                if (prev != '#')
                    ans += 2 * abs(s[j] - prev);
                prev = s[j];
            }
            i--;
            j++;
        }
        return ans;
    }
};