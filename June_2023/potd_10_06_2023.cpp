#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution
{
    public:
       void Rearrange(int arr[], int n)
        {
            // Your code goes here
            vector<int> v;
            stack<int> a;
            stack<int> b;
            stack<int> c;
            for(int i=0;i<n;i++){
                if(arr[i]<0) a.push(arr[i]);
                else b.push(arr[i]);
            }
            while(!a.empty()) {
                v.push_back(a.top());
                a.pop();
                
            }
            reverse(v.begin(),v.end());
            while(!b.empty()) {
                c.push(b.top());
                b.pop();
                
            }
            while(!c.empty()) {
                v.push_back(c.top());
                c.pop();
            }
            for(int i=0;i<n;i++) arr[i]=v[i];
        }
};