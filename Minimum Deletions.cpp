class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.size();
        vector<int>dp(n,0);
        for(int i= n-1;i>=0;i--){
            int prev=0;
            for(int j=i;j<n;j++){
                int temp=dp[j];
                if(i==j){
                    dp[j]=1;
                }
                else if(S[i]==S[j]){
                    dp[j]= 2+prev;
                }else{
                    dp[j]=max(dp[j],dp[j-1]);
                }
                prev=temp;
            }
        }
        return n-dp[n-1];
    } 
};
