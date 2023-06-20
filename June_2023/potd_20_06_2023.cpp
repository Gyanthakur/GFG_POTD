#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
class Solution {
  public:
    int matchGame(long long N) {
        // code here
        int res = N % 5;
        
        return res == 0 ? -1: res;
    }
};