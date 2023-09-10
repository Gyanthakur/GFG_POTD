#include<bits/stdc++.h>
using namespace std;
#define int long long
long long  t, a[100005];
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);

return 0;
}



struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution
{
    public:
        Node* insert(Node* node, int data) {
            if(node==NULL)
                node = new Node(data);
                if(node->data>data)
                    node->left=insert(node->left,data);
                if(node->data<data)
                    node->right=insert(node->right,data);
            return node;
    }

};