#include<bits/stdc++.h>

using namespace std;
class Node{
     int data;
     Node* left;
     Node* right;

     Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
     }
};

class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void inorder(Node *root,vector<int>& in1){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,in1);
        in1.push_back(root->data);
        inorder(root->right,in1);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int> in1;
     vector<int> in2;
     inorder(root1,in1);
     inorder(root2,in2);
     
     vector<int> ans;
     map<int,int> m;
     
     for(int i=0;i<in1.size();i++){
        m[in1[i]]++;
     }
     for(int i=0;i<in2.size();i++){
        m[in2[i]]++;
     }
     
     for(auto v:m){
         if(v.second==2){
             ans.push_back(v.first);
         }
     }
    
     return ans;
    }
};
