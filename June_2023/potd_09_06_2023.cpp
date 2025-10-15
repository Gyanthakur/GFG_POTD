#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        vector<string> v;
        sort(S.begin(), S.end());
        do
        {
            v.push_back(S);
        } while (next_permutation(S.begin(), S.end()));
        return v;
    }
};

// or

class Solution
{
public:
    int findFactorial(int n)
    {
        if (n == 1)
        {
            return 1;
        }

        return n * findFactorial(n - 1);
    };
    
    vector<string> find_permutation(string s)
    {
        vector<string> ans;
        unordered_map<string, int> container;
        sort(s.begin(), s.end());

        int n = findFactorial(s.length());
        container[s]++;
        ans.push_back(s);
        for (int i = 1; i < n; i++)
        {
            next_permutation(s.begin(), s.end());
            if (!container[s])
            {
                container[s]++;
                ans.push_back(s);
            }
        }

        return ans;
    }
};