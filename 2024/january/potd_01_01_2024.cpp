#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n&1) return false;
        
        for(int &x:nums) x = x%k;
        
        sort(begin(nums), end(nums));
        
        int zero = 0;
        for(int x:nums) if(!x) zero++;
        if(zero&1) return false;
        else if(zero == n) return true;
    
        int ans = 0;
        
        for(int i = 0; i<(n-zero)/2; i++){
            if(nums[zero+i] + nums[n-i-1] != k) return false;
        }
        return true;
    }
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