#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        int y=x;
        for(int i=0;i<n;i++)
        {
            if(s[i]== '1'){
                if(y>2*x) return 0;
                y=0;
            }
            else
                y++;
        }
        if(y>x)
        return 0;
        return 1;
    }
};