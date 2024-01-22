#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
struct Node
{
	int key;
	struct Node *left, *right;
};
class Solution
{
    private:
        void dfs(Node *root, int sum, int curr, vector<int> temp, vector<vector<int>> &ans) {
            if(root == NULL) return;
            curr += root->key;
            temp.push_back(root->key);
            
            if(curr == sum) 
                ans.push_back(temp);
            dfs(root->left, sum, curr, temp, ans);
            dfs(root->right, sum, curr, temp, ans);
        }
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, sum, 0, temp, ans);
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