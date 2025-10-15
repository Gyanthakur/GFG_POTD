#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class TrieNode
    {
    public:
        bool isEndOfWord;
        TrieNode *children[26];
        TrieNode()
        {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
        }

        void insert(string s1, TrieNode *root)
        {
            TrieNode *cur = root;
            for (int i = 0; i < s1.length(); i++)
            {
                int index = s1[i] - 'a';
                if (cur->children[index] == NULL)
                {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isEndOfWord = true;
        }

        bool search(string s1, TrieNode *root)
        {
            TrieNode *cur = root;
            for (int i = 0; i < s1.length(); i++)
            {
                int index = s1[i] - 'a';
                if (cur->children[index] == NULL)
                {
                    return false;
                }
                cur = cur->children[index];
            }
            return true;
        }
    };

    int prefixSuffixString(vector<string> &s1, vector<string> s2)
    {

        TrieNode *root = new TrieNode();

        for (int i = 0; i < s1.size(); i++)
        {
            root->insert(s1[i], root);
            reverse(s1[i].begin(), s1[i].end());
            root->insert(s1[i], root);
        }

        int ans = 0;
        for (int i = 0; i < s2.size(); i++)
        {

            string rev = s2[i];
            reverse(rev.begin(), rev.end());

            if (root->search(s2[i], root) || root->search(rev, root))
            {
                ans++;
            }
        }

        return ans;
    }
};