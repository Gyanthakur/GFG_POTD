//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// Linked list node structure
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

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution
{
public:
    long long multiplyTwoLists(Node *first, Node *second)
    {
        long long num1 = 0, num2 = 0;
        long long MOD = 1000000007;
        Node *cur1 = first;
        Node *cur2 = second;
        while (cur1 != nullptr)
        {
            num1 = num1 * 10 + cur1->data;
            cur1 = cur1->next;
        }
        while (cur2 != nullptr)
        {
            num2 = num2 * 10 + cur2->data;
            cur2 = cur2->next;
        }

        return (num1 * num2) % MOD;
    }
};
