

/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // Code here
    struct Node* x=new Node(data);
    x->npx=XOR(NULL,head);
    if(head)
    {
        head->npx=XOR(x,XOR(NULL,head->npx));
    }
    return x;
}

vector<int> getList(struct Node *head) {
    // Code here
    vector<int> ans;
    struct Node* prev=NULL;
    struct Node* next;
    while(head)
    {
        ans.push_back(head->data);
        next=XOR(prev,head->npx);
        prev=head;
        head=next;
    }
    return ans;
}
