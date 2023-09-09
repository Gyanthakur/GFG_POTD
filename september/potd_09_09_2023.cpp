#include<bits/stdc++.h>
using namespace std;
#define int long long
long long  t, a[100005];

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void inorder(Node*root ,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    //BST is basically a sorted array arr[n-k] is kth largest element
    int kthLargest(Node *root, int K)
    {  vector<int>ans;
       inorder(root,ans);
       int count =ans.size();
       //1 st largest is arr[1]
       //so kth largest is arr[n-k]
       if(K<=count)
       return ans[count-K];
       return -1;
    }
};
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);

return 0;
}