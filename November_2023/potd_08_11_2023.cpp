#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
class Solution
{   
    public:
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        int n = matrix.size();
        vector<int> ans;
        for (int i = 0; i<n; i++) {
            if (i%2) {
                for (int j = n-1; j>=0; j--) {
                    ans.push_back(matrix[i][j]);
                }
            }
            else {
                for (int j = 0; j<n; j++) {
                    ans.push_back(matrix[i][j]);
                }
            }
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