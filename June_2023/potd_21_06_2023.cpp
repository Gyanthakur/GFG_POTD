#include <bits/stdc++.h>
using namespace std;

int main()
{
  return 0;
}

class Solution
{
public:
  int sumOfNaturals(int n)
  {
    // code here
    long long ans = 0;
    long long temp = (pow(10, 9) + 7);
    ans = (((n % temp) * ((n + 1) % temp)) / 2) % temp;
    return ans % temp;
  }
};