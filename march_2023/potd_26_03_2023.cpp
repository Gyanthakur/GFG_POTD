#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=1;i<=leaves;i++)
        {
            m[i]=-1;
        }
        for(int i=0;i<N;i++)
        {
            int num=frogs[i];
            if(num<=leaves && m[num]==-1)
            {
                for(int j=frogs[i];j<=leaves;j+=frogs[i])
                {
                    m[j]=1; 
                }
            }
        }
    
        int cnt=0;
        for(int i=0;i<=leaves;i++)
        {
            if(m[i]==-1)
            cnt++;
        }
        return cnt;
    }
};