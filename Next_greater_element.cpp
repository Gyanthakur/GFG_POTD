class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;
        stack<int> s;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!s.empty() && nums2[s.top()]<=nums2[i]){
                s.pop();
            }
            m[nums2[i]]=s.empty()?-1:nums2[s.top()];
            s.push(i);
        }
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};
