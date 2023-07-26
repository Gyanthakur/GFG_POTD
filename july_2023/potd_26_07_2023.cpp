#include<bits/stdc++.h>
using namespace std;




struct Node
{
	int data;
	struct Node *left, *right;
};

void inorder(Node *root,int &cnt){
    if(root==NULL) return;
    cnt++;
    inorder(root->left, cnt);
    inorder(root->right, cnt);
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *temp = root;
    int cnt=0;
    
    inorder(temp,cnt);
    
    if(cnt==1) return -1;
    int parent[cnt+1]={0};
    for(int i=1;i<cnt;i++){
        parent[i]=i;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *aise = q.front();
        q.pop();
        
        if(aise->left){
            parent[aise->left->data]=aise->data;
            q.push(aise->left);
        }
        if(aise->right){
            parent[aise->right->data]= aise->data;
            q.push(aise->right);
        }
    }
    int count=0;
    
    while(parent[node]!=node){
        count++;
        if(count ==k){
            return parent[node];
        }
        node = parent[node];
    }
    return -1;
}
int main(){

return 0;
}