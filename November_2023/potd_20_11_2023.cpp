#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution{
  public:
  void dfs(Node* node, int currPathSum, int target, unordered_map<int, int>& pathCount, int& res) {
        if (node == NULL) {
            return;
        }

        currPathSum += node->data;
        res += pathCount[currPathSum - target];
        pathCount[currPathSum]++;

        dfs(node->left, currPathSum, target, pathCount, res);
        dfs(node->right, currPathSum, target, pathCount, res);

        pathCount[currPathSum]--;
    }
  
    int sumK(Node *root,int k)
    {
       unordered_map<int, int> pathCount;
        pathCount[0] = 1;
        int res = 0;
        dfs(root, 0, k, pathCount, res);
        return res;
    }
};long long  t;
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