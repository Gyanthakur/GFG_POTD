#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> res;

    void dfs(string &s, long long target, int idx, string path, long long eval, long long prev)
    {
        if (idx == s.size())
        {
            if (eval == target)
                res.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++)
        {
            if (i != idx && s[idx] == '0')
                break; // skip leading zero numbers
            string curStr = s.substr(idx, i - idx + 1);
            long long cur = stoll(curStr);

            if (idx == 0)
            {
                dfs(s, target, i + 1, curStr, cur, cur);
            }
            else
            {
                dfs(s, target, i + 1, path + "+" + curStr, eval + cur, cur);
                dfs(s, target, i + 1, path + "-" + curStr, eval - cur, -cur);
                dfs(s, target, i + 1, path + "*" + curStr, eval - prev + prev * cur, prev * cur);
            }
        }
    }

    vector<string> addOperators(string s, int target)
    {
        res.clear();
        dfs(s, target, 0, "", 0, 0);
        sort(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "125";
    int target = 7;
    vector<string> ans = sol.addOperators(s, target);
    for (auto &expr : ans)
        cout << expr << " ";
}