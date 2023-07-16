#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
       //int i= q.size();
       stack<int>ans;
       while(!q.empty()){
           ans.push(q.front());
           q.pop();
       }
       while(!ans.empty()){
           q.push(ans.top());
           ans.pop();
       }
       
       
       
       return q;
    }
};