#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    bool matchPattern(string &word, string &patternToMatch)
    {
        string patternInWord = "";

        for (char c : word)
        {
            if (isupper(c))
                patternInWord += c;
            if (patternInWord == patternToMatch)
                return true;
        }

        return patternInWord == patternToMatch;
    }

    vector<string> CamelCase(int n, vector<string> dictionary, string pattern)
    {
        // code here
        vector<string> ans;

        for (string word : dictionary)
        {
            if (matchPattern(word, pattern))
            {
                ans.push_back(word);
            }
        }

        sort(begin(ans), end(ans));

        if (ans.empty())
            ans.push_back("-1");

        return ans;
    }
};