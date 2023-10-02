#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
// #define int long long
long long  t;
class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	   int n=s.size();
	   int k= 1e9+7;
	   unordered_map<char,long long int>u;
	   for(int i=n-1;i>=0;i--){
	       long long int a=0;
	       for(auto x:u)a=(a+x.second)%k;
	       u[s[i]]=a+ (u.find(s[i])!=u.end());
	   }
	   long long int ans=0;
	   for(auto x:u)ans=(ans+ x.second)%k;
	   int a=ans+1;
	   return a;
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