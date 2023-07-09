#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++){
            if(arr[i]<=0) arr[i]=0;
        }
        
        for(int i=0;i<n;i++){
            int ind =abs(arr[i])-1;
            if(ind>=0 and ind<n and arr[ind]>=0){
                if(arr[ind]==0) arr[ind]=-999999;
                else arr[ind]=-arr[ind];
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>=0) return i+1;
        }
        return n+1;
    } 
};