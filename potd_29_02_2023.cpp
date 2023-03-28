#include<bits/stdc++.h>
using namespace std;





class Solution
{
    public:
    int countSubstring(string s)
    {
        int n=s.length();
        int * a = new int[n];
        int l=0,u=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(isupper(s[i]))
            a[i]=1; 
            else
            a[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(a[j]==1)
                u+=1;
                else
                l+=1;
            
            if(l==u)
                {
                    cnt++;
                }
            
            }
            l=0;u=0;
        }
        return cnt;
    }
};