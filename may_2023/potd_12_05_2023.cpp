#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

int arrayOperations(int n, vector<int> &arr) {
        int cnt=0,s=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                cnt++;
                while(i<n and arr[i]!=0) i++;
            }
            if(i<n and arr[i]==0) s=1;
        }
        return s==1 ? cnt: -1;
    }