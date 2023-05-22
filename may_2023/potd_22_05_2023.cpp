#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
    public:
    int solve(int N, vector<int> p){
        unordered_map<int , int> mp;
        
        for(int i = 1; i < N ; i++){
            mp[p[i]]++;
        }
        int ans ;
        if(mp[0]==1)ans = mp.size()-2;
        else ans = mp.size()-1;
        
        
        if(ans<0)ans = 0;
        return ans;
        
        
    }
};