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
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
     
     Node *node = root;
        return getHt(node) != -1;
        
    }
    int getHt(Node *node){
        if(!node)
        return 0;
        int leftHt = getHt(node -> left);
        if(leftHt == -1){
            return -1;
        }
        int rightHt = getHt(node -> right);
        if(rightHt == -1){
            
            return -1;
        }
        int htDiff = abs(leftHt-rightHt);
        if(htDiff > 1){
            
            return -1;
        }
        return 1 + max(leftHt,rightHt);
        //  Your Code here
    }