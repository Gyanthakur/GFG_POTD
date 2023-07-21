#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}\

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* ptr=head, *rev_head=NULL, *rev_tail=NULL, *prev_rev_tail=NULL, *main_rev_head=NULL;
        int count=k;
        while(ptr)
        {
            node* new_node=(struct node*)malloc(sizeof(struct node));
            new_node->data=ptr->data;
            new_node->next=NULL;
            if(rev_head==NULL)
            {
                rev_head=new_node;
                rev_tail=new_node;
            }
            else {
                new_node->next=rev_head;
                rev_head=new_node;
            }
            if(prev_rev_tail==NULL)
            main_rev_head=rev_head;
            if(prev_rev_tail!=NULL)
            prev_rev_tail->next=rev_head;
            ptr=ptr->next;
            count--;
            if(count==0)
            {
                prev_rev_tail=rev_tail;
                rev_tail=NULL;
                rev_head=NULL;
                count=k;
            }
        }
        return main_rev_head;
    }
};