#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution{
    public:
    bool isPowerOfFive(string s) {
    int n = s.length();
    if (n == 0) return false;
    if (s[0] == '0') return false;  
    long long num = 0, p=1;
    for (int i = n-1; i >= 0; i--) {
        if(s[i]=='1'){
            num+=p;
        }
        p=p*2;
    }
    if (num == 0) return false;
    
    while (num > 1) {
        if (num % 5 != 0) return false;
        num /= 5;
    }
    return true;
}
int cuts(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0')
        return -1;
    if (isPowerOfFive(s))
        return 1;
    int minCuts = INT_MAX;
    for (int i = 1; i < n; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (isPowerOfFive(left)) {
            int cutsRight = cuts(right);
            if (cutsRight != -1)
                minCuts = min(minCuts, 1 + cutsRight);
        }
    }
    if (minCuts != INT_MAX)
        return minCuts;
    return -1; 
}
};