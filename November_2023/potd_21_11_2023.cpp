#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
struct Node {
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
    // return true/false denoting whether the tree is Symmetric or not
    bool check(Node* r1,Node* r2)
    {
        if(r1==NULL||r2==NULL)
        {
            if(r2==r1)
            return 1;
            return 0;
        }
        
        return (r1->data==r2->data)&&check(r1->left,r2->right)&&check(r1->right,r2->left);
    }
    bool isSymmetric(struct Node* root)
    {
     if(root==NULL)
     return 1;
     
     return check(root->left,root->right);
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