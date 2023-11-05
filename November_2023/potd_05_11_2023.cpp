#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
    vector<int> v;
    map<int, int> mp;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int count = 1;
    for (int i = 1; i <= n; i++) {
        while (i < n && nums[i] == nums[i - 1]) {
            count++;
            i++;
        }
        mp[nums[i - 1]] = count;
        count = 1;
    }

    vector<pair<int, int>> temp;
    for (auto &it : mp) {
        temp.push_back(it);
    }

    sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first; // If frequencies are the same, sort by value in descending order
        } else {
            return a.second > b.second;
        }
    });

    for (int i = 0; i < k && i < temp.size(); i++) {
        v.push_back(temp[i].first);
    }
    return v;

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
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}