#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *iter = head;
        Node *sec = head->next;
        Node *prev = NULL;

        while (iter && iter->next)
        {
            Node *second = iter->next;

            iter->next = second->next;
            second->next = iter;

            if (prev)
                prev->next = second;

            prev = iter;
            iter = iter->next;
        }

        return sec;
    }
};

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