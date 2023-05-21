#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution {
  public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers) {
        int sum=0;
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        for(int i=0;i<passengers.size();i++){
            sum+=abs(chairs[i]-passengers[i]);
        }
        return sum;
    }
};