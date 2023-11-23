#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};


class Solution {
public:
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    Node* rotateRight(Node* currentNode) {
        Node* newRoot = currentNode->left;
        Node* newRootRightSubtree = newRoot->right;

        newRoot->right = currentNode;
        currentNode->left = newRootRightSubtree;

        currentNode->height = max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* rotateLeft(Node* currentNode) {
        Node* newRoot = currentNode->right;
        Node* newRootLeftSubtree = newRoot->left;

        newRoot->left = currentNode;
        currentNode->right = newRootLeftSubtree;

        currentNode->height = max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    int getBalance(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* insertToAVL(Node* node, int data) {
        // Base case: If the node is null, create a new node with the given data.
        if (node == nullptr) {
            return new Node(data);
        }

        // Recursive insertions
        if (node->data > data) {
            node->left = insertToAVL(node->left, data);
        } else if (node->data < data) {
            node->right = insertToAVL(node->right, data);
        } else {
            // Duplicate data is not allowed in AVL trees.
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        
        int balance = getBalance(node);

        
        if (balance > 1 && node->left->data > data) {
            return rotateRight(node);
        }
        if (balance < -1 && node->right->data < data) {
            return rotateLeft(node);
        }
        if (balance > 1 && node->left->data < data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && node->right->data > data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
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