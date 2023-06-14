#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        priority_queue<int>pq;
        for(long long i=0;i<N;i++){
            pq.push(A[i]);
        }
        long long ans=0;
        while(K--){
            long long maxi=pq.top();
            pq.pop();
            ans+=maxi;
            pq.push(maxi/2);
        }
        return ans;
    }
};