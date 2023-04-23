#include<bits/stdc++.h>
using namespace std;



class Solution{
public:
    
      int minimumNumber(int n,vector<int> &arr){
        if(n<=1)return 0;
        int res=arr[0];
        for(int i=0;i<n;i++)
        {
             res=__gcd(min(res,arr[i]),max(res,arr[i]));
        }
        return res;
    }
};