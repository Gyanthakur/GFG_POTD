/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node* dummy1 = new Node(0);
        Node* dummy2 = new Node(0);
        Node* list1 = dummy1;
        Node* list2 = dummy2;
        bool alternate = true;
        while(head) {
            if(alternate) {
                list1->next = head;
                list1 = list1->next;
            }
            else {
                list2->next = head;
                list2 = list2->next;
            }
            head = head->next;
            alternate = !alternate;
        }
        list1->next = nullptr;
        list2->next = nullptr;
        return {dummy1->next, dummy2->next};
    }
};
