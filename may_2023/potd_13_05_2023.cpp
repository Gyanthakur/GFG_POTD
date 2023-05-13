#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

  int bitMagic(int n, vector<int> &arr) {
        // code here
        
        int l =0 , r =n-1 ,ans =0 ;
        while(l<=r)
        {
            if(arr[l++]!=arr[r--])
            ans++; 
        }
        if(ans%2==0)
        return ans/2 ;
        return ans/2 + 1 ;
    }