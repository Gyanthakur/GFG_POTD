#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        unordered_map<int,int>m;
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto a:m)
        {
            if(a.second==1)v.push_back(a.first);
        }
        sort(v.begin(),v.end());
        return v;
    }
};