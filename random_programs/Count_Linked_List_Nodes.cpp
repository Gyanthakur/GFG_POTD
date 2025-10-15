#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node *head)
    {

        // Code here
        int c = 0;
        while (head)
        {
            head = head->next;
            c++;
        }
        return c;
    }
};