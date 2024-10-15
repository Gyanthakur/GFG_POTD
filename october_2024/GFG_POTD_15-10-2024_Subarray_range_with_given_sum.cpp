class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
       int n = arr.size();
       unordered_map<int, int>mp;
       int cur = 0;
       int count = 0;
       for(int i= 0;i<n;i++)
       {
           cur+= arr[i];
           if(cur== tar){
               count++;
           }
           int nLeft = cur - tar;
           if(mp.find(nLeft) != mp.end()){
               count +=mp[nLeft];
           }
           mp[cur]++;
       }
       return count;
    }
};
