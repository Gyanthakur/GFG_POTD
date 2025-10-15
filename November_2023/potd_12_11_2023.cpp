#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int num1 = str1.size(), i, j = 2;
        if (num1 != str2.size())
            return false;
        else
        {
            for (i = 0; i < num1; ++i)
            {
                if ((str1[j] != str2[i]) && (str2[j] != str1[i]))
                    return false;
                j = (j + 1) % num1;
            }
        }
        return true;
    }
};

void solution()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}