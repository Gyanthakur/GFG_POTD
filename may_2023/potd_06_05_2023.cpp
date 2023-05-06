#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<bool>> dp(K+1, vector<bool> (target+1, 0));
        dp[0][0] = 1;
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= K; i++){
            for(int j = 1; j <= target; j++){
                for(int k = 0; k < N; k++){
                    if(coins[k] <= j){
                        int x = coins[k];
                        if(dp[i-1][j-x]){
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }
        return dp[K][target];
    }
};