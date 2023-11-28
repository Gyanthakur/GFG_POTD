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
    int sumOfDependencies(vector<int> adj[], int v) {
        // code here
        int c=0;
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                c++;
            }
        }
        return c;
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