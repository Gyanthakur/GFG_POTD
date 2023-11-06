#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        // Mellow World, Hellow CODERS!!!
        //Drink Water, keep yourself hydrated.
        int R = mat.size();
        int C = mat[0].size();
        vector<int> ans;
        auto valid = [&](int r, int c) -> int {
            return 0<= r && r < R && 0<=c && c < C;
        };
        for(int i = 0; i<q; ++i){
            int ty = queries[i][0];
            int r_ul = queries[i][1] - ty;
            int r_ll = queries[i][1] + ty;
            int c_ul = queries[i][2] - ty;
            int c_ll = queries[i][2] + ty;
            
            int sum = 0;
            
            int r = r_ul, c = c_ul;
            
            while(r <= r_ll){
                if(valid(r,c))
                    sum += mat[r][c];
                r++;
            }
            r--;
            c++;
            while(c <= c_ll){
                if(valid(r,c)) sum += mat[r][c];
                c++;
            }
            r--;
            c--;
            while(r>=r_ul){
                
                if(valid(r,c)) sum+= mat[r][c];
                r--;
            }
            r++;c--;
            while(c>c_ul){
                if(valid(r,c))
                    sum += mat[r][c];
                c--;
            }
            ans.push_back(sum);
            
           
            
            
        }
        return ans;
    }
};
void solution()
{

}
signed main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}