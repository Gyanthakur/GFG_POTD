// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    
    int countPairsWithDiffK(vector<int>& arr, int k) {
        int cnt=0;
        map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]-k>0 && mpp.find(arr[i]-k)!=mpp.end()){
                cnt+=mpp[arr[i]-k];
            }
        }
        return cnt;
    }
};
