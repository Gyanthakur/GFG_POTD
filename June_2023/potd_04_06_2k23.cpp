#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    bool isNum(char ch)
    {
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
            return true;
        return false;
    }

    string reverseEqn(string s)
    {
        stack<string> st;
        string str = "", res = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (isNum(s[i]))
                str += s[i];
            else
            {
                res += s[i];
                st.push(str);
                st.push(res);
                str = "";
                res = "";
            }
        }
        st.push(str);

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};