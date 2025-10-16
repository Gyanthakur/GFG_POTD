#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

string encode(string src)
{
  // Your code here
  int length = src.length();
  int count = 0;
  int i = 0;
  string ans = "";

  while (i < length)
  {
    char a = src[i];
    ans += a;
    while (src[i] == a)
    {
      count++;
      i++;
    }
    ans += to_string(count);
    count = 0;
  }
  return ans;
}

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