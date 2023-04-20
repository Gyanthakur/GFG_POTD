#include<bits/stdc++.h>
using namespace std;





class Solution{

    public:
    unordered_map<Node*, Node*> parent;
    
    void getParent(Node* root, int home, Node* &source, Node* par)
    {
        if(!root) return ;
        parent[root] = par;
        if(root-> data == home ) 
            source= root;
            
        getParent(root->left, home , source, root);
        getParent(root->right, home, source, root);
        
    }
    
    int ladoos(Node* root, int home, int k)
    {
        Node* source=NULL;
        getParent(root,home,source, NULL);
        
        queue<Node*> Q;
        Q.push(source);
        int ans=0;
        unordered_set<Node*> ust;
        ust.insert(source);
        while(Q.size())
        {
            int size= Q.size();
            for(int i=0;i< size;i++)
            {
                Node* cur= Q.front();
                Q.pop();
                ans+= cur-> data;
                // cout<<cur-> data<<" ";
                
                if(cur->left && ust.count(cur->left)==0)
                {
                    Q.push(cur->left);
                    ust.insert(cur->left);
                }
                if(cur->right && ust.count(cur->right) ==0 )
                {
                    Q.push(cur->right);
                    ust.insert(cur->right);
                }
                if(parent[cur] && ust.count(parent[cur])==0)
                {
                    Q.push(parent[cur]);
                    ust.insert( parent[cur]);
                }
            }
            if(k==0) break;
            k--;
        }
        return ans;
    }


};