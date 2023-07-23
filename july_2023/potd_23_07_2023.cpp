#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
//  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(!head) return head;
        
        stack<Node*> s;
        Node* dummynode = new Node(-1);
        Node* dummy = dummynode;
        
        Node *curr = head;

        int slecte = 2;
        while(slecte != -1){
            if(curr->data == slecte)
            s.push(curr);
            
            
            curr = curr->next;
            if(curr == NULL){
                curr = head;
                slecte--;
            }
        }
        
        while(!s.empty()){
            dummy->next = s.top();
            dummy = dummy->next;
            s.pop();
        }
        
        dummy->next = NULL;
        head = dummynode->next;
        dummynode->next = nullptr;
        delete dummynode;
        
        return head;
    }
};