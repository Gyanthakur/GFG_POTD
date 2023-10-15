class Solution{
    private:
    void inOrderUtil(Node *root,  vector<int>&nodes) {
        if(root == NULL) return;
        inOrderUtil(root->left,nodes);
        nodes.push_back(root->data);
        inOrderUtil(root->right,nodes);
    }
    Node *createBstFromInorder(vector<int>&nodes, int l, int r) {
        if( l > r) return NULL;
        int mid = (l + r)/2;
        Node *root = new Node(nodes[mid]);
        root->left = createBstFromInorder(nodes,l,mid-1);
        root->right = createBstFromInorder(nodes,mid+1,r);
        
        return root;
    }
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	if(root == NULL) return NULL;
    	vector<int>nodes;
    	inOrderUtil(root,nodes);
    	int size = nodes.size();
    	return createBstFromInorder(nodes,0,size-1);
    }
};
