#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}







class Solution{
public:
    void make_arr(Node* node, vector<Node*>& arr)
    {
        if(node==NULL)  return;
        arr.push_back(node);
        make_arr(node->left, arr);
        make_arr(node->right, arr);
    }
    void solve_count(Node* node, int& k, set<int>& list, int& flag)
    {
        if(list.size()>k)
        {
            flag = 1;
            return;
        }
        if(node==NULL || flag)  return;
        list.insert(node->data);
        solve_count(node->left, k, list, flag);
        solve_count(node->right, k, list, flag);
    }
    int goodSubtrees(Node *root,int k){
        vector<Node*> arr;
        set<int> list;
        int result = 0, flag ;
        make_arr(root, arr);
        for(auto i: arr)
        {
            list.clear();
            flag = 0;
            solve_count(i, k, list, flag);
            if(!flag)    result++;
        }
        return result;
    }
};