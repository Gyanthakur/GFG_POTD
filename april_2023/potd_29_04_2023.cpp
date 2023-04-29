#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution{
public:
    long long findNumber(long long N){
        long long ans=0, num=1;
        vector<int> val={9,1,3,5,7};
        while(N){
            ans+=val[N%5]*num;
            
            if(N%5==0) N=N/5-1;
            else N=N/5;
            
            num*=10;
        }
        return ans;
    }
};