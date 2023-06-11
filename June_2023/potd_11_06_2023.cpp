#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}class Solution{
    public:
   void update(int a[], int n, int updates[], int k)
    {
        // Your code goes here
        for(int i = 0; i < k; i++)
            a[updates[i]-1]++;
        for(int i = 1; i < n; i++){
            a[i] += a[i - 1];
        }
    }

};