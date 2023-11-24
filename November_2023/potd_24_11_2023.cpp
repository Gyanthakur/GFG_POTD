#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        int mod = 1e9 + 7;
        vector<long long> ans(n, 0);
        ans[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = i; j >= 0; j--){
                ans[j+1] += ans[j];
                ans[j+1] %= mod;
            }
        }
        
        return ans;
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