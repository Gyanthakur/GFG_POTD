#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        long long ans;
        int i=2;
        while(i<N){
            if(N%i==0){
                N/=i;
            }
           else{ i++;}
        }
        ans=N;
        return ans;
    }


};