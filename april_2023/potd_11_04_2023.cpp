#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int solve(int a, int b, int c) {
        
        int ar[3]={a,b,c};
        sort(ar,ar+3);
        int x=(ar[0]+ar[1])*2;
        if(ar[2]>x)
        return -1;
        else
        return a+b+c;
    }
};