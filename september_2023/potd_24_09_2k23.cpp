#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution
{
public:
vector<int>duplicates(int a[],int n)
{
unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    vector<int> v;
    for (auto x : m)
    {
        if (x.second >= 2)
        {
            // cout << x.first << endl;
            v.push_back(x.first);
        }
     }
     sort(v.begin(), v.end());
     if(v.size() != 0)
     {
         return v;
     }
     return {-1};
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