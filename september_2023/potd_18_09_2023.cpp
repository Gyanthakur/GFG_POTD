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
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {

        // Your code here
        // if(n%2==0)return "YES";
        // else return "NO";
        // return (n>0 && (n&(n-1)) == 0)? true : false;
        return n ? n == pow(2, (int)log2(n)) : 0;
    }
};

void solution()
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}