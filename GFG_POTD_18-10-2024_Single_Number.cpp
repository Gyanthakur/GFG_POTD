// User function template for C++
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            ans=ans^arr[i];
        }
        return ans;
    }
};
