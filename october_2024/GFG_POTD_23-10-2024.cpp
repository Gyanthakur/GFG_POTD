class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        int m=0;
        int sum=0;
        Node* temp=head;
        while(temp!=NULL){
            sum+=temp->data;
            m++;
            temp=temp->next;
        }
        int p=m-n;
        while(p>0 && head!=NULL){
            sum-=head->data;
            head=head->next;
            p--;
        }
        return sum;
    }
};
