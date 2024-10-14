//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
         snode* s1 = NULL;
         
         
         vector<int>ans;
     
        // Current node of first BST
        Node* current1 = root1;
     
        // s2 is stack to hold nodes of second BST
        snode* s2 = NULL;
     
        // Current node of second BST
        Node* current2 = root2;
     
        // If first BST is empty, then output is inorder
        // traversal of second BST
        if (root1 == NULL) {
            inorder(root2,ans);
            return ans;
        }
        // If second BST is empty, then output is inorder
        // traversal of first BST
        if (root2 == NULL) {
            inorder(root1,ans);
            return ans;
        }
     
        // Run the loop while there are nodes not yet printed.
        // The nodes may be in stack(explored, but not printed)
        // or may be not yet explored
        while (current1 != NULL || !isEmpty(s1)
               || current2 != NULL || !isEmpty(s2)) {
            // Following steps follow iterative Inorder
            // Traversal
            if (current1 != NULL || current2 != NULL) {
                // Reach the leftmost node of both BSTs and push
                // ancestors of leftmost nodes to stack s1 and
                // s2 respectively
                if (current1 != NULL) {
                    push(&s1, current1);
                    current1 = current1->left;
                }
                if (current2 != NULL) {
                    push(&s2, current2);
                    current2 = current2->left;
                }
            }
            else {
                // If we reach a NULL node and either of the
                // stacks is empty, then one tree is exhausted,
                // print the other tree
                if (isEmpty(s1)) {
                    while (!isEmpty(s2)) {
                        current2 = pop(&s2);
                        current2->left = NULL;
                        inorder(current2,ans);
                    }
                    return ans;
                }
                if (isEmpty(s2)) {
                    while (!isEmpty(s1)) {
                        current1 = pop(&s1);
                        current1->left = NULL;
                        inorder(current1,ans);
                    }
                    return ans;
                }
     
                // Pop an element from both stacks and compare
                // the popped elements
                current1 = pop(&s1);
                current2 = pop(&s2);
     
                // If element of first tree is smaller, then
                // print it and push the right subtree. If the
                // element is larger, then we push it back to
                // the corresponding stack.
                if (current1->data < current2->data) {
                    ans.push_back(current1->data);
                    current1 = current1->right;
                    push(&s2, current2);
                    current2 = NULL;
                }
                else {
                    ans.push_back(current2->data);
                    current2 = current2->right;
                    push(&s1, current1);
                    current1 = NULL;
                }
            }
        }
        
        return ans;
    
    
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
