#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int>v;
        for(int i=0;i<arr.size();i++)
        {
            if(v.size()>0)
            {
                if(v[v.size()-1]>=0 && arr[i]<0  || v[v.size()-1]<0 && arr[i]>=0)
                    v.pop_back();
                else
                    v.push_back(arr[i]);
            }
            else
                v.push_back(arr[i]);
        }
        return v;
    }
};