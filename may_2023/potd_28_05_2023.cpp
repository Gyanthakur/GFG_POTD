#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
 struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       vector<int>v;
       Node *temp = head;
       while(temp->next!=NULL)
       {
           v.push_back(temp->data);
           temp = temp->next;
       }
       v.push_back(temp->data);
       if(v.size()<n || n==0)
       return -1;
       return v[v.size()-n];
}