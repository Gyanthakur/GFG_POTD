// #include<bits/stdc++.h>
// using namespace std;
// int main(){

// return 0;
// }

// class Solution
// {
//     public:
//     queue<int> rev(queue<int> q)
//     {
//         // add code here.
//        //int i= q.size();
//        stack<int>ans;
//        while(!q.empty()){
//            ans.push(q.front());
//            q.pop();
//        }
//        while(!ans.empty()){
//            q.push(ans.top());
//            ans.pop();
//        }

//        return q;
//     }
// };

/*
#include<bits/stdc++.h>
using namespace std;

int foo(int &p,int q)
    {
        q=q-1;
        if(q==0)
            return 1;
        p=p+1;
        return foo(p,q)*p;
    }

int main(){
    int n=4;
    cout<<foo(n,n);
return 0;
}
*/