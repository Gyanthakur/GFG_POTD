#include<bits/stdc++.h>
using namespace std;






class Solution{
public:
int dominantPairs(int n,vector<int> &arr){
    int dominantPairsCount = 0;
    sort(arr.begin(), arr.begin() + n/2);
    sort(arr.begin() + n/2, arr.end());
    int i = 0, j = n/2;
    while (i < n/2 && j < n) {
        if (arr[i] >= 5 * arr[j]) {
            dominantPairsCount += n/2 - i;
            j++;
        } else {
            i++;
        }
    }
    return dominantPairsCount;
    }
};