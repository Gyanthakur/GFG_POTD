#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[++top1] = x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       arr[--top2] = x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        
        if(top1 == -1)   return top1;
        
        int topElem1 = arr[top1--];
        
        return topElem1;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2 == size)   return -1;
        
        int topElem2 = arr[top2++];
        
        return topElem2;
    }
};

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int y1=22;
//     int y2=11;
//     int y3=12;
//     y1=y2++;
//     y2=--y3;
//     y3=y1+y2+y3+++y2++;
//     cout<<y1<<y2<<y3;
// return 0;
// }   