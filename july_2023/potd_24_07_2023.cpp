#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       Node *head=root;
       vector<int>ans;
       queue<Node*> q;
        q.push(root);
        Node *temp;
        int len;
        int res;
        while(!q.empty()){
            len=q.size();
		    vector<int> v;
            for(int i=0;i<len;i++){
                temp=q.front();
                q.pop();
                res=temp->data;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
		ans.push_back(res);
        }
		return ans;
    }
};