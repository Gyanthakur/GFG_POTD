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
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	  // Your code goes here
        vector<int> sum(n,0);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                    sum[i]=max(sum[i],sum[j]);
                }
            }
            sum[i]+=arr[i];
        }
        return *max_element(sum.begin(),sum.end());
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