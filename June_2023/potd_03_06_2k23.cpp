#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
     int sum1=0,sum2=0,sum3=0;
     for(auto i:S1) sum1+=i;
     for(auto i:S2) sum2+=i;
     for(auto i:S3) sum3+=i;
     int i=0,j=0,k=0;
     while(i<N1 && j<N2 && k<N3){
         if(sum1==sum2 && sum2==sum3){
             return sum1;
         }
         int a=max(sum1,max(sum2,sum3));
         if(a==sum1){
             sum1-=S1[i++];
         }
         else if(a==sum2) sum2-=S2[j++];
         else if(a==sum3) sum3-=S3[k++];
     }
     return 0;

    }
};