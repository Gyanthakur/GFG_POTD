class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int> ans;
        int n = nums.size();
        int first=-1, second=-1, count1=0, count2=0;
        for(int i : nums){
            if(i==first) count1++;
            else if(i==second) count2++;
            else if(count1==0){
                count1++;
                first=i;
            }
            else if(count2==0){
                count2++;
                second=i;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1=0;
        count2=0;
        
        for(int num : nums){
            if(num==first){
                count1++;
            }
            if(num==second){
                count2++;
            }
        }
        
        if(count1 > n/3) ans.push_back(first);
        if(count2 > n/3) ans.push_back(second);
        if(ans.empty()) return {-1};
        return ans;
    }
};
