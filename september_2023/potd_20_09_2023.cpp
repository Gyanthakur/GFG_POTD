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
  vector<int> rotate(int n, int d)
  {
    // code here.
    d = d % 16;
    int l = (n << d) | (n >> (16 - d));
    int r = (n >> d) | (n << (16 - d));
    int mask = (1 << 16) - 1;
    l &= mask; // taking only the first 16 bits
    r &= mask; // taking only the first 16 bits
    return {l, r};
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