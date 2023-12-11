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
   long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long sum=0,maxsum;
        for(int i=0;i<k;i++)sum+=arr[i];
        maxsum=sum;
        for(int j=k;j<n;j++){
             sum=sum-arr[j-k]+arr[j];
             maxsum = max(maxsum,sum);
        }
        return maxsum;
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