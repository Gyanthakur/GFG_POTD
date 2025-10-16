#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    return 0;
}

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        Node *temp = head;
        Node *ans = NULL;

        unordered_map<int, int> m;
        while (temp != NULL)
        {
            if (m.find(temp->data) == m.end())
            {
                m[temp->data]++;
                ans = temp;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
                ans->next = temp;
            }
        }
        return head;
    }
};