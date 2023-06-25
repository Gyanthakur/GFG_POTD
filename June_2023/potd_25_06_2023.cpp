#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution
{
    public:
    #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        vector<vector<int>> ans;
        for(int i=0 ; i< row; i++) {
            vector<int> temp (M[i],M[i]+col);
            auto it = find(ans.begin(),ans.end(),temp);
            if(it == ans.end()) ans.push_back(temp);
        }
        return ans;
        
    }
};