#include<bits/stdc++.h>
using namespace std;
#define int long long
long long  t, a[100005];

class Solution{
public:
   bool isLucky(int n) {
        int r=2;
        while(r<=n){
            int p=n/r;
            if(n%r==0){
                return 0;
            }
            n-=p;
            r++;
        }
        return 1;
    }


};
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);

return 0;
}