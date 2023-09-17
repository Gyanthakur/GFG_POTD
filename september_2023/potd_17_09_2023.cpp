#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
vector<long long> printFibb(int n) 
    {
        vector<long long> dp(n, 0);
        
        dp[0] = 1; dp[1] = 1;
        
        for(int i=2; i<n; i++) dp[i] = dp[i-1] + dp[i-2];
     
        return dp;
    }
long long  t;
void solution()
{

}
int32_t main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}