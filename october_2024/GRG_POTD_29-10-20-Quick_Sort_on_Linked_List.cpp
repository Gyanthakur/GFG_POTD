//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// structure of the node of the singly linked list is as

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// // a node of the singly linked list
// struct node
// {
//     int data;
//     struct node *next;

//     node(int x)
//     {
//         data = x;
//         next = NULL;
//     }
// };

// Solution class with quickSort function
class Solution
{
public:
    struct Node *findPivot(struct Node *head)
    {
        if (!head->next)
        {
            return head;
        }
        int p = head->data;
        struct Node *j = head->next;
        struct Node *i = head;
        int temp;
        while (j)
        {
            if (j->data < p)
            {
                i = i->next;
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        temp = head->data;
        head->data = i->data;
        i->data = temp;
        return i;
    }

    void sortQ(struct Node *head)
    {
        if (!head)
        {
            return;
        }
        struct Node *pivot = findPivot(head);
        struct Node *pre = nullptr;
        struct Node *curr = head;
        while (curr != pivot)
        {
            pre = curr;
            curr = curr->next;
        }
        if (pre)
        {
            pre->next = nullptr;
            sortQ(head);
            pre->next = pivot;
        }

        sortQ(pivot->next);
    }

    struct Node *quickSort(struct Node *head)
    {
        // code here
        sortQ(head);
        return head;
        // s truct Node* quickSort(struct Node* head) {
        //  code here
    }
};