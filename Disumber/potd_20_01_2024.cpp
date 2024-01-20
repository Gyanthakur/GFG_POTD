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
    int ans=0;
    int solve(Node* root){
        if(!root)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        ans+=abs(l)+abs(r);
        return root->key+l+r-1;
    }
    int distributeCandy(Node* root)
    {
        //code here
        solve(root);
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