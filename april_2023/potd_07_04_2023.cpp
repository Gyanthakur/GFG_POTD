#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int addMinChar(string str){ 
        int n = str.length();
        int i=0;int j=n-1;
        
        int ans=0;
        while(i<=j)
        {
            if(str[i++]==str[j--])
            {
                
            }
            else
            {
                ans++;
                i=0;
                j=n-1-ans;
            }
        }
        return ans;
    }
};