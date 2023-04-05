#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        
        map<int,int>m;
        int count=0;
        for(int i=0;i<N;i++)
        {
            m[arr[i]]++;
        }
        for(int i=0;i<N;i++)
        {
            if(arr[i]==1)
            {
                if(m[arr[i]]>1)return N;
                else
                return N-1;
            }
            if(m[arr[i]]>1)
            {
                count++;
            }
            else
            {
                for(auto it=m.begin();it!=m.end();it++)
                {
                    int x=it->first;
                    if(x!=arr[i])
                    {
                        if(arr[i]%x==0)
                        {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};