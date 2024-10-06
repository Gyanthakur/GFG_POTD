/*
GFG POTD 5 oct 2024

Problem Description:

Given a sorted array arr[] of positive integers, 
find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:

Input: arr[] = [1, 2, 3]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
Input: arr[] = [3, 6, 9, 10, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.

*/

// Solution in C++

#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define all(v) v.begin() , v.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

long long findSmallest(vector<int> &arr) {
    long long smallest =1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>smallest) {
            break;
        }
        else{
            smallest+=arr[i];
        }
    }
    return smallest;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++ ){
    cin >> arr[i];
   }
   cout << findSmallest(arr) << endl;
}
