#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> uniquePerms(vector<int> &arr)
  {
    // code here
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr);
    while (next_permutation(arr.begin(), arr.end()))
      ans.push_back(arr); // next_permutaion is an funtion that creates the permutation automatically in the greater lexicographic way.
    return ans;
  }
};