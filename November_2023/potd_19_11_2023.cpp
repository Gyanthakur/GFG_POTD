#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        Node *s1 = head1;
        Node *s2 = head2;

        while (s1 != NULL && s2 != NULL)
        {
            if (s1->data == s2->data)
            {
                curr->next = new Node(s1->data);
                curr = curr->next;
                s1 = s1->next;
                s2 = s2->next;
            }
            else if (s1->data < s2->data)
            {
                s1 = s1->next;
            }
            else
            {
                s2 = s2->next;
            }
        }

        Node *result = dummy->next;
        delete dummy;
        return result;
    }
};

long long t;
void solution()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}