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
    int minDist(int a[], int n, int x, int y) {
        // code here
        int X=-1,Y=-1;
        int ans  = n+1 ;
        for(int i=0;i<n;i++)
        {
            if(x==a[i])
            {
                X = i;
            }
            else if(y==a[i])
            {
                Y = i;
            }
            if(X!=-1 && Y != -1)
            {
                int diff=abs(X-Y);
                ans=min(diff,ans);
            }
            
        }
        return ans==n+1?-1:ans;
        
        
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