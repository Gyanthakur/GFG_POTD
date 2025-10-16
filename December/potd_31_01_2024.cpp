#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

struct TrieNode
{
    struct TrieNode *children[26];
    bool isLeaf;
    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Solution
{
public:
    bool containsKey(char a, struct TrieNode *root)
    {
        return root->children[a - 'a'] != NULL;
    }
    void put(char a, struct TrieNode *Node, struct TrieNode *root)
    {
        root->children[a - 'a'] = Node;
    }
    TrieNode *get(char a, struct TrieNode *Node)
    {
        return Node->children[a - 'a'];
    }
    void setEnd(struct TrieNode *Node)
    {
        Node->isLeaf = true;
    }
    void insert(struct TrieNode *root, string key)
    {
        for (int i = 0; i < key.length(); i++)
        {
            if (!containsKey(key[i], root))
            {
                put(key[i], new TrieNode(), root);
            }
            root = get(key[i], root);
        }
        setEnd(root);
    }

    // Function to use TRIE data structure and search the given string.
    bool search(struct TrieNode *root, string key)
    {
        for (int i = 0; i < key.length(); i++)
        {
            if (!containsKey(key[i], root))
                return false;
            root = get(key[i], root);
        }
        return root->isLeaf;
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