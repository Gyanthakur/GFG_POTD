#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long i=0,j=0,cnt=0,pro=1,ans=0;
        for(i=0;i<n;i++){
            pro=1,cnt=0,j=i;
            while(j<n && pro*a[j]<k){
                cnt++;
                pro*=a[j];
                j++;
            }
            ans+=cnt;
        }
        return ans;
    }
};