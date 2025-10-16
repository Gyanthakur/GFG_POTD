#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

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

class Solution
{
public:
    struct Node *modifyTheList(struct Node *head)
    {
        // add code here.
        vector<int> arr;
        Node *ans = head;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        int n = arr.size();
        for (int i = 0; i < n / 2; i++)
        {
            ans->data = arr[n - 1 - i] - arr[i];
            ans = ans->next;
        }
        for (int i = n / 2; i < n; i++)
        {
            ans->data = arr[n - i - 1];
            ans = ans->next;
        }
        return head;
    }
};