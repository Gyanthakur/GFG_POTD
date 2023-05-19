#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        map<int,int> m;
        for(int i=0;i<N;i++){
            m[hand[i]]++;
        }
        
        for(auto i: m){
            int cnt= i.second;
            int x= i.first;
            
            if(cnt==0) continue;
            
            for(int j=0;j<groupSize;j++){
                if(m[x+j]==0) return false;
                m[x+j]-=cnt;
            }
        }
        
        return true;       
}