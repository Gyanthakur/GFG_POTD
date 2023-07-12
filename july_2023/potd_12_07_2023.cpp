#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int n,int R)
    {
        long long N =n;
        int mod=(1e9+7);
        long long ans=1;
       while(R){
           if(R%2==0){N=(N*N)%mod; R/=2;}
           else {ans=(ans*(N)%mod)%mod; R--;}
       }
        return ans;
    }

};