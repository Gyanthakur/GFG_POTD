#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    unordered_map<int, int> umap;
    // Function to insert element into the queue
    void insert(queue<int> &q, int k)
    {
        q.push(k);
        umap[k]++;
    }

    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k)
    {
        if (umap.find(k) != umap.end())
            return umap[k];
        else
            return -1;
    }
};