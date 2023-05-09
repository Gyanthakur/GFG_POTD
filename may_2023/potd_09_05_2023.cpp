#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

const int mod = 1e9+7;
void multiply(long long int F[2][2], long long int M[2][2]);
void power(long long int F[2][2], long long int n);

int fib(long long int n)
{
    long long int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0];
}
void power(long long int F[2][2], long long int n)
{
    if(n == 0 || n == 1) return;

    long long int M[2][2] = {{1, 1}, {1, 0}};
    
    power(F, n / 2);
    multiply(F, F);
    
    if (n % 2 != 0)
        multiply(F, M);
}
void multiply(long long int F[2][2], long long int M[2][2])
{
    int x = ((F[0][0]%mod * M[0][0]%mod)%mod + (F[0][1]%mod * M[1][0]%mod)%mod)%mod;
    int y = ((F[0][0]%mod * M[0][1]%mod)%mod + (F[0][1]%mod * M[1][1]%mod)%mod)%mod;
    int z = ((F[1][0]%mod * M[0][0]%mod)%mod + (F[1][1]%mod * M[1][0]%mod)%mod)%mod;
    int w = ((F[1][0]%mod * M[0][1]%mod)%mod + (F[1][1]%mod * M[1][1]%mod)%mod)%mod;
    
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

class Solution {
  public:
    int countStrings(long long int n)
    {
        int res = fib(n+2);
        return res;
    }
};