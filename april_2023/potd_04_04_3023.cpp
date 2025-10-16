#include <bits/stdc++.h>
using namespace std;

// string contains only "a" and "b" many times   like "aabbbabbbabbb", "abbababbababba", "ab"
int minSteps(string str)
{
    int ans = 0;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] != str[i - 1])
            ans++;
    }
    return ans / 2 + 1;
}

int main()
{
    string s;
    cin >> s;
    int ans = minSteps(s);
    cout << ans << endl;
}