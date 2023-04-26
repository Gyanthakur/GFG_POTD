#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}


class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        for(int i=0;i<m;i++){
            if(n==0)return true;
            if(i==0 && seats[i]==0 && seats[i+1]==0){
                n--;
                seats[i]=1;
            }
            else if(i==m-1 && seats[i]==0 && seats[i-1]==0){
                n--;
                seats[i]=1;
            }
            else if(seats[i]==0 && seats[i-1]==0 && seats[i+1]==0){
                n--;
                seats[i]=1;
            }
        }
        if(n==0)return true;
        return false;
    }
};