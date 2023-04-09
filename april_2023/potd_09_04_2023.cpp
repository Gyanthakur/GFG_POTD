#include<bits/stdc++.h>
using namespace std;








int done=0;
vector<long long>f, inv;
class Solution {
    const long long M=1e9+7;
  public:
    int bestNumbers(int N, int A, int B, int C, int D) {
        if(!done) pre();
        if(A==B)
        {
            long long sum=(long long)N*A;
            bool flag=false;
             while(sum>0)
            {
                if((sum%10)==C or (sum%10)==D) 
                {
                    flag=true;
                    break;
                }
                sum/=10;
            }
            if(flag) return 1;
            return 0;
        }
        long long ans=0;
        for(long long i=0;i<=N;i++)
        {
            long long sum = i*A+(N-i)*B;
            bool flag=false;
            while(sum>0)
            {
                if((sum%10)==C or (sum%10)==D) 
                {
                    flag=true;
                    break;
                }
                sum/=10;
            }
            if(flag) ans=(ans+nCr(N, i))%M;
        }
        return ans;
    }
    void pre()
    {
        done=1;
        f.resize(1e5+1, 1);
        inv.resize(1e5+1);
        for(int i=2;i<=1e5;i++) f[i]=(f[i-1]*i)%M;
        inv[1e5]=fastpow(f[1e5], M-2);
        for(int i=1e5-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%M;
    }
    long long fastpow(long long a, long long n)
    {
        long long res=1;
        while(n>0)
        {
            if(n&1) res=(res*a)%M;
            a=(a*a)%M;
            n>>=1;
        }
        return res;
    }
    long long nCr(int n, int r)
    {
        return (((f[n]*inv[n-r])%M)*inv[r])%M;
    }
};
