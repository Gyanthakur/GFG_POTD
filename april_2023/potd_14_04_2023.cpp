#include<bits/stdc++.h>
using namespace std;





class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<int>s1,s2;
        int i=0;
        while(i<n)
        {
            if(!s1.empty() && !s2.empty() && s1.top()==color[i] && s2.top()==radius[i])
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                s1.push(color[i]);
                s2.push(radius[i]);
            }
            i++;
        }
        return s1.size();
        
    }
};