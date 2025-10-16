//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* A linked list node */

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert()
{
    int n, value;
    cin >> n;
    struct Node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/
class Solution
{
public:
    Node *get(struct Node *odd)
    {
        if (odd->next == NULL || odd->next->next == NULL)
        {
            return odd;
        }
        Node *temp = odd->next->next;
        Node *last = temp->next;
        temp = get(temp);
        //   Node * temp1=temp;
        //   while(temp1->next!=NULL)
        //   {
        //       temp1=temp1->next;
        //   }
        if (last == NULL)
        {
            temp->next = odd->next;
            odd->next->next = NULL;
            odd->next = temp;
        }
        else
        {

            last->next = odd->next;
            odd->next->next = NULL;
            odd->next = temp;
        }
    }
    void rearrange(struct Node *odd)
    {
        // add code here

        get(odd);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends