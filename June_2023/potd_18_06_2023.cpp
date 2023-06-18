#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
  public:
    int distributeTicket(int N, int K) {
    bool order=true;
    int start=1, end=N;
    while(1)
    {
        if(end-start<=K)
        {
            if(order)
                return end;
            else
                return start;
        }
        if(order)
        {
            start+=K;
        }
        else
        {
            end-=K;
        }
        order=!order;
    }
    return 0;
  }
};
